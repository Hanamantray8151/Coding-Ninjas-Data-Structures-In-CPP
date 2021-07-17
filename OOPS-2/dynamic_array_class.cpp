#include<bits/stdc++.h>
using namespace std;

class DynamicArray{
	private:
		int *data;
		int nextIndex;
		int capacity;	//Total size of initial array.
	public:
		DynamicArray(){
			data = new int[5];
			nextIndex = 0;
			capacity = 5;
		}
		DynamicArray(DynamicArray const &d1){   //To Overcome the shallow copy here user creates own copy constructor to make deep copy.
			//this -> data = d1.data;	//Shallow Copy.
			
			//Deep Copy.
			this -> data = new int[d1.capacity];
			for(int i=0;i<d1.capacity;i++){
				this -> data[i] = d1.data[i];
			}
			this -> nextIndex = d1.nextIndex;
			this -> capacity = d1.capacity;
		}
		void operator=(DynamicArray const &d1){ //To Overcome the shallow copy here user creates own copy constructor to make deep copy.
			//this -> data = d1.data;	//Shallow Copy.
			
			//Deep Copy.
			this -> data = new int[d1.capacity];
			for(int i=0;i<d1.capacity;i++){
				this -> data[i] = d1.data[i];
			}
			this -> nextIndex = d1.nextIndex;
			this -> capacity = d1.capacity;
		}
		void add(int element){
			if(nextIndex == capacity){
				int *newData = new int[2 * capacity];
				for(int i=0;i<capacity;i++){
					newData[i] = data[i];
				}
				delete [] data;
				data = newData;
				capacity = capacity * 2;
			}
			data[nextIndex] = element;
			nextIndex++;
		}
		void add(int i,int element){
			if(i < nextIndex){
				data[i] = element;
			}else{
				return;
			}
		}
		void print() const{
			for(int i=0;i<nextIndex;i++){
				cout << data[i] << " ";
			}
			cout << endl;
		}
};

int main(){
	DynamicArray d1;
	
	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.add(60);
	
	d1.print();
	
	DynamicArray d2(d1);  //Once Inbuilt copy constructor is called then automatically shallow copy is called. 
	d1.add(0,100);
	cout << "d1 : ";
	d1.print();
	cout << "d2 : ";
	d2.print();
	
	DynamicArray d3;      
	d3 = d1;              //once Inbuilt copy assignment operator is called then automatically shallow copy is called.
	d1.add(0,200);
	cout << "d1 : ";
	d1.print();
	cout << "d3 : ";
	d3.print();
	
	return 0;
}
