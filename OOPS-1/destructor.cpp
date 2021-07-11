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
		~Student(){
			cout << "Destructor is called !" <<endl;
		}
};

int main(){
	Student s1(10,1001);
	Student s2(20,1002);
	Student *s3 = new Student(30,1003);
	
	cout << "s1 : ";
	s1.display();
	cout << "s2 : ";
	s2.display();
	cout << "s3 : ";
	s3 -> display();
	
	delete s3;	//We have created s3 dynamically so we have to call deallocate explicitly;
              //Destructor is called just before exiting the function.
	return 0;
}
