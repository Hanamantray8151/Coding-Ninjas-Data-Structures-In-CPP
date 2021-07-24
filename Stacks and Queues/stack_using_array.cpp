#include<bits/stdc++.h>
using namespace std;

class Stack{
	private:
		int *data;
		int top;
		int capacity;
		
	public:
		Stack(int totalsize){
			this -> data = new int[totalsize];
			this -> top = 0;
			this -> capacity = totalsize;
		}
		
		int size(){
			return top;
		}
		
		bool isEmpty(){
			if(top == 0){
				return true;
			}
			return false;
		}
		
		void push(int element){
			if(top == capacity){
				cout << "Stack is full." << endl;
				return;
			}
			data[top] = element;
			top++;
		}
		
		int pop(){
			if(isEmpty()){
				cout << "Stack is empty." << endl;
				return -1;
			}
			top--;
			return data[top];
		}
		
		int topOfStack(){
			return data[top - 1];
		}	
};

int main(){
	Stack s(4);
	
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
