#include<bits/stdc++.h>
using namespace std;

class Student{
	public: 
		int rno;
		int age;
		Student(int r){
			cout << "Constructor 1 called !" << endl;
			this -> rno = r;
		}
		Student(int a,int r){
			cout << "Constructor 2 called !" << endl;
			this -> age = a;
			this -> rno = r;
		}
		void display(){
			cout << age << " " << rno << endl;
		}
};

int main(){
	Student s1(10,1001);
	Student s2(20,1002);
	Student *s3 = new Student(30,1003);
	
	s2 = s1;	//all the properties of s1 object are copied into s2 object.
	cout << "s1 : ";
	s1.display();
	cout << "s2 : ";
	s2.display();
	
	s1 = *s3;	//all the properties of s3 object are copied into s1 object.
	cout << "s3 : ";
	s3 -> display();
	cout << "s1 : ";
	s1.display();
	
	return 0;
}
