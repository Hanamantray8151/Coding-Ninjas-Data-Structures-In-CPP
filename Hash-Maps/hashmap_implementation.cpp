#include<bits/stdc++.h>
using namespace std;

template<typename V>
class Mapnode{
	public:
		string key;
		V value;
		Mapnode* next;
		
		Mapnode(string key,V value){
			this -> key = key;
			this -> value = value;
			this -> next = NULL;
		}
		
		~Mapnode(){
			delete next;
		}
};

template<typename V>
class Ourmap{
	Mapnode<V>** buckets;
	int count;
	int numBuckets;
	
	public:
		Ourmap(){
			count = 0;
			numBuckets = 5;
			buckets = new Mapnode<V>*[numBuckets];
			for(int i=0;i<numBuckets;i++){	//Initialising the bucket array with NULL values.
				buckets[i] = NULL;
			}
		}
		
		~Ourmap(){
			for(int i=0;i<numBuckets;i++){
				delete buckets[i];
			}
			delete [] buckets;
		}
		
		int size(){	
			return count;
		}
		
		V getValue(string key){	//Function which takes key and gives value.
			int bucketIndex = getBucketIndex(key);
			Mapnode<V>* head = buckets[bucketIndex];
			
			while(head != NULL){
				if(head->key == key){	//If key found then return it's value.
					return head -> value;
				}
				head = head -> next;
			}
			return 0;	//If key not found then return 0(default value).
		}
		
	private:
		int getBucketIndex(string key){
			int hashcode = 0;
			int currentCoeff = 1;
			
			for(int i=key.length()-1;i>=0;i--){
				hashcode = hashcode + (key[i] * currentCoeff);
				hashcode = hashcode % numBuckets;	//To be safer,if hashcode comes out of range.
				
				currentCoeff = currentCoeff * 37;
				currentCoeff = currentCoeff % numBuckets;	//To be safer,if currentCoeff comes out of range.
			}
			return hashcode % numBuckets;
		}
		
	public:
		double getLoadFactor(){
			return (1.0 * count)/numBuckets;
		}
		void rehash(){
			Mapnode<V>** temp = buckets;
			buckets = new Mapnode<V>*[2 * numBuckets];
			
			for(int i=0;i<numBuckets;i++){
				buckets[i] = NULL;
			}
			
			int oldBucketCount = numBuckets;
			numBuckets = numBuckets * 2;
			count = 0;
			
			for(int i=0;i<oldBucketCount;i++){
				Mapnode<V>* head = temp[i];
				while(head != NULL){
					string key = head -> key;
					V value = head -> value;
					
					insert(key,value);
					head = head -> next;
				}
			}
			
			for(int i=0;i<oldBucketCount;i++){
				Mapnode<V>* head = temp[i];
				delete head;
			}
			delete [] temp;
		}
	
		void insert(string key,V value){	//Function which takes key and value for insertion. 
			int bucketIndex = getBucketIndex(key);
			Mapnode<V>* head = buckets[bucketIndex];
			
			while(head != NULL){	//Traverse the linked list till end to check the key already exists or not.
				if(head->key == key){
					head -> value = value;
					return;
				}
				head = head -> next;
			}
			
			head = buckets[bucketIndex];	//Re-initialization of head because after while loop head becomes NULL.
			//If key is not found.
			Mapnode<V>* newNode = new Mapnode<V>(key,value);
			newNode -> next = head;
			buckets[bucketIndex] = newNode;
			count++;
			
			double loadFactor = (1.0 * count)/numBuckets;
			if(loadFactor > 0.7){
				rehash();
			}
		}
		
		V remove(string key){	//Function which takes key and removes that key,gives corresponding key value.
		 	int bucketIndex = getBucketIndex(key);
		 	Mapnode<V>* head = buckets[bucketIndex];
		 	Mapnode<V>* prev = NULL;
		 	
		 	while(head != NULL){
		 		if(head->key == key){
		 			if(prev == NULL){	//If the key is found in the beginning.
		 				buckets[bucketIndex] = head -> next;
		 			}else{
		 				prev -> next = head -> next;	//If the key is found at the middle.
		 			}
		 			V prevValue = head -> value;	//Store prevValue of deleting node and return it.
		 			head -> next = NULL;
		 			delete head;
		 			count--;	//Decrement the counter after deletion of every node.
		 			return prevValue;
		 		}
		 		prev = head;
		 		head = head -> next;
		 	}
		 	return 0;	//If the removing key is not present in the list then return 0(default value).
		}
};

int main(){
	Ourmap<int> m;
	
	for(int i=0;i<10;i++){
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		int value = i + 1;
		m.insert(key,value);
		cout << m.getLoadFactor() << endl;
	}
	
	m.remove("abc2");
	
	for(int i=0;i<10;i++){
		char c = '0' + i;
		string key = "abc";
		key = key  + c;
		cout << key << " : " << m.getValue(key) << endl;
	}
	
	cout << m.size() << endl;

	return 0;
}
