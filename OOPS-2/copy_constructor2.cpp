#include<bits/stdc++.h>
using namespace std;

class Student{
	private:
		int age;
	public:
		char *name;
		Student(int age,char *name){
			this -> age = age;
			//this -> name = name;	Shallow Copy.
			
			//Deep Copy.
			this -> name = new char[strlen(name) + 1];
			strcpy(this -> name,name);
		}
		//Student(Student s){	//If we write this,here it will go infinite loop bcz we need copy constructor and passing copy constructor as argument this is bad.
		Student(Student const &s){	//if we write this,here s is reference to the s1 object,that means s and s1 are pointing towards same memory bloack.
			this -> age = s.age;
			//this -> name = s.name;	Shallow Copy.
			
			//Deep Copy.
			this -> name = new char[strlen(s.name) + 1];
			strcpy(this -> name,s.name);
		}
		void print(){
			cout << name << " " << age << endl;
		}
};

int main(){
	char name[] = "abcd";
	Student s1(20,name);
	s1.print();
	
	Student s2(s1);	//Copy Constructor called.
	s2.name[0] = 'x';
	s1.print();
	s2.print();
	
	return 0;
}



