#include<bits/stdc++.h>
using namespace std;

class Student{
	private:
		int age;
		char *name;
	public:
		Student(int age,char *name){
			this -> age = age;
			//Shallow Copy.
			//this -> name = name;
			
			//Deep Copy.
			this -> name = new char[strlen(name) + 1];
			strcpy(this -> name,name);
		}
		void print(){
			cout << name << " " << age << endl;
		}
};

int main(){
	char name[] = "abcd";
	Student s1(20,name);
	s1.print();
	
	name[3] = 'e';
	Student s2(24,name);
	s2.print();
	s1.print();
	
	return 0;
}
