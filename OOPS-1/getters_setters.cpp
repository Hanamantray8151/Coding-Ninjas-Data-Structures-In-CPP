#include<bits/stdc++.h>
using namespace std;

class Student{
	public:
		int rno;
	private:
		int age;
	public:
		int getAgeRno(){
			return age;
		}
		void setAgeRno(int a,int b){
			age = a;
			rno = b;
		}
		void display(){
			cout << age << " " << rno << endl;
		}
};

int main(){
	Student s1;
	Student* s2 = new Student;
	s1.setAgeRno(20,101);
	s2->setAgeRno(25,102);
	
	s1.display();
	s2->display();
	return 0;
}
