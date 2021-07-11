#include<bits/stdc++.h>
using namespace std;

class Student{
	public:
		int age;
		int rollnumber;
};

int main(){
	Student s1;
	s1.age = 20;
	s1.rollnumber = 101;
	cout << s1.age << " " << s1.rollnumber << endl;
	
	Student* s2 = new Student;
	s2->age = 25;
	s2->rollnumber = 102;
	cout << s2->age << " " << s2->rollnumber << endl;
	return 0;
}
