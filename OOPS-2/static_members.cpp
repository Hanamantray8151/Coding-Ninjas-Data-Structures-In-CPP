#include<bits/stdc++.h>
using namespace std;

class Student{
	static int totalstudents;	//Total number of students.
	public:
		int age;
		int rno;
		
		Student(){
			totalstudents++;
		}
		static int getTotalStudents(){	//Inside Static functions we can access only static properties.
			return totalstudents;
		}
};

int Student :: totalstudents = 0;	//Initialization of static data member.

int main(){
	Student s1;
	Student s2;
	Student s3;
	
	//cout << Student :: totalstudents << endl;
	cout << Student :: getTotalStudents() << endl;

	return 0;
}
