#include<bits/stdc++.h>
using namespace std;

class DynamicStack{
	private:
		int *data;
		int top;
		int capacity;
		
	public:
		DynamicStack(){
			this -> top = 0;
			this -> capacity = 4;
			this -> data = new int[capacity];
		}
		
		bool isEmpty(){
			if(top == 0){
				return true;
			}
			return false;
		}
		
		void push(int element){
			if(top == capacity){
				int *newData = new int[2 * capacity];
				for(int i=0;i<capacity;i++){
					newData[i] = data[i];
				}
				capacity = capacity * 2;
				delete [] data;
				data = newData;	
			}
			data[top] = element;
			top++;
		}
		
		int topOfStack(){
			return data[top - 1];
		}
		
		int pop(){
			if(isEmpty()){
				return -1;
			}
			top--;
			return data[top];
		}
		
		int size(){
			return top;
		}
};

int main(){
	DynamicStack s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	cout << s.topOfStack() << endl;
	
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
	cout << s.size() << endl;
	
	cout << s.isEmpty() << endl;
	
	return 0;
}
