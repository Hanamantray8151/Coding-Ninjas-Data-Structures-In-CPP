#include<bits/stdc++.h>
using namespace std;

class Student{
	public:
		int age;
		const int rno;	//Constant variable.
		int &x;	//reference variable for age;
	Student(int r,int age) : rno(r),age(age),x(this -> age){  //We must use initialization list to initialize constant variables at the time of declaration.
                                                            	  //for Non constant variables it's optional.
	}
	void print(){
		cout << age << " " << rno << " " << x << endl;
	}	
};

int main(){
	Student s1(101,20);
	s1.print();
	
	return 0;
}
