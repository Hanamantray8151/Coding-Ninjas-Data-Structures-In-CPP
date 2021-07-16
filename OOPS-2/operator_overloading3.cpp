#include<bits/stdc++.h>
using namespace std;

class Math{
	private:
		int num;
	public:
		Math(int num){
			this -> num = num;
		}
		Math operator++(int) {
			Math mNew(this -> num);
			this -> num = this -> num + 1;
			return mNew;
		}
		Math& operator+=(Math const &m4){
			this -> num = this -> num + m4.num;
			return *this; 
		}
		void print(){
			cout << num << endl;
		}
};

int main(){
	int n;
	cin >> n;
	
	Math m1(n);
	cout << "m1 : ";
	m1.print();
	
	Math m2 = m1++;	//Post-Increment(++) Operator Overloading.
	cout << "m1 : ";
	m1.print();
	cout << "m2 : ";
	m2.print();
	
	Math m3(n);
	Math m4(n);
	m3 += m4;		//+= Operator Overloading.
	cout << "m3 : ";
	m3.print();
	cout << "m4 : ";
	m4.print();
	
	return 0;
}
