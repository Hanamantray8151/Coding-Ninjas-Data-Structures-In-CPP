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
	Student s2(s1);	//static to static copy.
	
	cout << "s1 : ";
	s1.display();
	cout << "s2 : ";
	s2.display();
	
	Student *s3 = new Student(20,1002);
	Student s4(*s3);	//dynamic to static copy.
	
	cout << "s3 : ";
	s3 -> display();
	cout << "s4 : ";
	s4.display();
	
	Student s5(30,1003);
	Student *s6 = new Student(s5);	//static to dynamic copy.
	
	cout << "s5 : ";
	s5.display();
	cout << "s6 : ";
	s6 -> display();
	
	Student *s7 = new Student(40,1004);
	Student *s8 = new Student(*s7);	//dynamic to dynamic copy.
	
	cout << "s7 : ";
	s7 -> display();
	cout << "s8 : ";
	s8 -> display();
	
	return 0;
}
