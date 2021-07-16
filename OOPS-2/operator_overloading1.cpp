#include<bits/stdc++.h>
using namespace std;

class Math{
	private:
		int number;
	public:
		Math(int number){
			this -> number = number;
		}
	
		Math operator+(Math const &m2) const{
			int sum = this -> number + m2.number;
			return sum;
		}
		Math operator*(Math const &m2) const{
			int product = this -> number * m2.number;
			return product;
		}
		bool operator==(Math const &m2) const{
			return (this -> number == m2.number);
		}
		void print(){
			cout << number << endl;
		}
};

int main(){
	int a,b;
	cin >> a >> b;
	Math m1(a);
	Math m2(b);
	
	cout << "m1 : ";
	m1.print();
	cout << "m2 : ";
	m2.print();
	
	Math m3 = m1 + m2;	//+ Operator Overloading.
	cout << "m3 : ";
	m3.print();
	
	Math m4 = m1 * m2;	//* Operator Overloading.
	cout << "m4 : ";
	m4.print();
	
	if(m1 == m2){		//== Operator Overloading.
		cout << "Equal !" << endl;
	}else{
		cout << "Not equal !" << endl;
	}
	
	return 0;
}
