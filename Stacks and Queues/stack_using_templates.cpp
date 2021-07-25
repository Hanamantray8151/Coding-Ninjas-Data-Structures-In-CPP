#include<bits/stdc++.h>
using namespace std;

template <typename T>
class DynamicStack{
	private:
		T *data;
		int top;
		int capacity;
		
	public:
		DynamicStack(){
			this -> top = 0;
			this -> capacity = 4;
			this -> data = new T[capacity];
		}
		
		bool isEmpty(){
			if(top == 0){
				return true;
			}
			return false;
		}
		
		void push(T element){
			if(top == capacity){
				T *newData = new T[2 * capacity];
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
		
		T topOfStack(){
			return data[top - 1];
		}
		
		T pop(){
			if(isEmpty()){
				cout << "Stack is empty." << endl;
				return 0;
			}
			top--;
			return data[top];
		}
		
		int size(){
			return top;
		}
};

int main(){
	DynamicStack<char> s;
	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');

	/*
	DynamicStack<double> s;
	s.push(10.43);
	s.push(11.43);
	s.push(12.43);
	s.push(13.43);
	s.push(14.43);
	*/
	
	/*
	DynamicStack<int> s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	*/
	
	cout << s.topOfStack() << endl;
	
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
	cout << s.size() << endl;
	
	cout << s.isEmpty() << endl;
	
	return 0;
}
