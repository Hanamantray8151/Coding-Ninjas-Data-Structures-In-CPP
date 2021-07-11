#include<bits/stdc++.h>
using namespace std;

class Student{
	private:
		int age;
	public:
		int rno;
		//Default Constructor.
		Student(){
			cout << "Default Constructor is Called !" << endl;
		}
		
		//Parameterized Constructor with one parameter.
		Student(int rno){
			cout << "Parameterized Constructor with 1 parameter is called !" << endl;
			this -> rno = rno;	//Here we have to use this keyword compulsory.
		}
		
		//Parameterized Constructor with two parameters.
		Student(int a,int r){
			cout << "Parameterized Constructor with 2 parameter is called !" << endl;
			this -> age = a;	//Here this keyword is optional.
			this -> rno = r;
		}
		
		void display(){
			cout << age << " " << rno << endl;
		}	
};

int main(){
	Student s1(101);
	s1.display();
	
	Student* s2 = new Student(102);
	s2->display();
	
	Student s3(30,1001);
	s3.display();
	
	Student s4(1002);
	s4.display();
	return 0;
}
