#include<bits/stdc++.h>
using namespace std;

class Queue{
	private:
		int *data;
		int nextIndex;
		int firstIndex;
		int size;
		int capacity;
	
	public:
		Queue(){
			this -> data = new int[5];
			this -> nextIndex = 0;
			this -> firstIndex = -1;
			this -> size = 0;
			this -> capacity = 5;
		}
		
		int getSize(){
			return size;
		}
		
		bool isEmpty(){
			if(size == 0){
				return true;
			}
			return false;
		}
		//Insert an element into queue.
		void enqueue(int element){
			if(size == capacity){
				//cout << "Queue is Full." << endl;
				//return;
				int *newData = new int[2 * capacity];
				int j = 0;
				for(int i=firstIndex;i<capacity;i++){
					newData[j] = data[i];
					j++;
				}
				for(int i=0;i<firstIndex;i++){
					newData[j] = data[i];
					j++;
				}
				delete [] data;
				data = newData;
				firstIndex = 0;
				nextIndex = capacity;
				capacity = capacity * 2;
			}
			
			data[nextIndex] = element;
			nextIndex = (nextIndex + 1) % capacity;
			
			if(firstIndex == -1){
				firstIndex = 0;
			}
			size++;
		}
		//Return the front data of a queue.
		int front(){
			if(isEmpty()){	//if(firstIndex == -1) we can use both.
				cout << "Queue is Empty." << endl;
				return 0;
			}
			return data[firstIndex];
		}
		//Deleting an element from a queue.
		int dequeue(){
			if(isEmpty()){
				cout << "Queue is Empty." << endl;
				return 0;
			}
			int ans = data[firstIndex];
			firstIndex = (firstIndex + 1) % capacity;
			size--;
			if(size == 0){
				firstIndex = -1;
				nextIndex = 0;
			}
			return ans;
		}
};

int main(){
	Queue q;
	
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	
	cout << q.front() << endl << endl;
	
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl << endl;
	
	cout << q.getSize() << endl;
	cout << q.front() << endl;;
	cout << q.isEmpty() << endl;

	return 0;
}
