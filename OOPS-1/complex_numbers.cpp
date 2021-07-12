#include<bits/stdc++.h>
using namespace std;

class ComplexNumbers{
	private:
		int real;
		int imaginary;
	public:
		ComplexNumbers(int real,int imaginary){
			this -> real = real;
			this -> imaginary = imaginary;
		}
		void plus(ComplexNumbers c2){
			int r = this -> real + c2.real;
			int i = this -> imaginary + c2.imaginary;
			this -> real = r;
			this -> imaginary = i;
		}
		void multiply(ComplexNumbers c2){
			int r = (this -> real * c2.real) - (this -> imaginary * c2.imaginary);
			int i = (this -> real * c2.imaginary) + (c2.real * this -> imaginary);
			this -> real = r;
			this -> imaginary = i;
		}
		void print(){
			cout << this -> real << " + " << this -> imaginary << "i" << endl;
		}
};

int main(){
	//Addition of two complex numbers.
	ComplexNumbers c1(3,2);
	ComplexNumbers c2(4,3);
	
	cout << "c1 : ";
	c1.print();
	cout << "c2 : ";
	c2.print();
	
	c1.plus(c2);
	cout << "Sum : ";
	c1.print();
	
  	//Product of two complex numbers.
	ComplexNumbers c3(4,2);
	ComplexNumbers c4(6,3);
	
	cout << "c3 : ";
	c3.print();
	cout << "c4 : ";
	c4.print();
	
	c3.multiply(c4);
	cout << "Product : ";
	c3.print();
	
	return 0;
}
