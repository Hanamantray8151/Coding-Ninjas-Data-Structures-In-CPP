#include<bits/stdc++.h>
using namespace std;

class Math{
	private:
		int num;
	public:
		Math(int num){
			this -> num = num;
		}
		Math& operator++(){	//Here & used bcz it returns the value as reference to the current object.
					//That means this is pointing to the same object next time when we increment further.
			this -> num = this -> num + 1;
			return *this;
		}
		void print(){
			cout << num << endl;
		}
};

int main(){
	int num;
	cin >> num;
	Math m1(num);
	cout << "m1 : ";
	m1.print();
	
	/* Math m2 = ++m1;	//Pre-Increment(++) Operator Overloading.	
	cout << "m2 : ";
	m2.print(); */
	
	Math m3 = ++(++m1);	//This uses extra block to make copy of 1st increment.
	cout << "m3 : ";
	m3.print();
	cout << "m1 : ";
	m1.print();
	 
	
	return 0;
}
