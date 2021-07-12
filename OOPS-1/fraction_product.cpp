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
		void product(Fraction const &f2){	//by passing const reference we can't change value of f2.
			int num = this -> numerator * f2.numerator;
			int denom = this -> denominator * f2.denominator;
			this -> numerator = num;
			this -> denominator = denom;
			
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
	
	f1.product(f2);
	
	cout << "Product : ";
	f1.print();
	return 0;
}
