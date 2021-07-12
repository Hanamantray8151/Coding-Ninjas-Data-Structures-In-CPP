#include<bits/stdc++.h>
using namespace std;

class Fraction{
	private:
		int numerator;
		int denominator;
	public:
		Fraction(int numerator,int denominator){
			this -> numerator = numerator;
			this -> denominator = denominator;
		}
		void simplify(){
			int gcd = 1;
			int j = min(this -> numerator,this -> denominator);
			for(int i=1;i<=j;i++){
				if(this -> numerator % i == 0 && this -> denominator % i == 0){
					gcd = i;
				}
			}
			this -> numerator = this -> numerator / gcd;
			this -> denominator = this -> denominator / gcd;
		}
		void add(Fraction f2){
			int lcm = this -> denominator * f2.denominator;
			int x = lcm/this -> denominator;
			int y = lcm/f2.denominator;
			int num = ((x * this -> numerator) + (y * f2.numerator));
			this -> numerator = num;
			this -> denominator = lcm;
			
			simplify();
		}
		void print(){
			cout << this -> numerator << "/" << this -> denominator << endl;
		}
};

int main(){
	Fraction f1(10,2);
	Fraction f2(15,4);
	
	cout << "f1 : ";
	f1.print();
	cout << "f2 : ";
	f2.print();
	
	f1.add(f2);
	
	cout << "Sum : ";
	f1.print();
	
	return 0;
}
