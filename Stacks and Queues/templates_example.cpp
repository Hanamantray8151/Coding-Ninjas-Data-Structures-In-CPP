#include<bits/stdc++.h>
using namespace std;

template <typename T,typename V>
class Pair{
	private:
		T x;
		V y;
		
	public:
		void setX(T x){
			this -> x = x;
		}
		
		T getX(){
			return x;
		}
		
		void setY(V y){
			this -> y = y;
		}
		
		V getY(){
			return y;
		}
};

int main(){
	Pair <Pair <int,int>,int> p1;
	
	Pair <int,int> p2;
	p2.setX(10);
	p2.setY(20);
	
	p1.setX(p2);
	p1.setY(30);
	
	cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;
	
	/*
	Pair <int,double> p1;
	p1.setX(50);
	p1.setY(50.5);
	
	cout << p1.getX() << " " << p1.getY() << endl;
	*/
	
	/*
	Pair <int> p1;
	
	p1.setX(10);
	p1.setY(20);
	
	cout << p1.getX() << " " << p1.getY() << endl;
	
	Pair <double> p2;
	p2.setX(120.24);
	p2.setY(130.34);
	
	cout << p2.getX() << " " << p2.getY() << endl;
	
	Pair <char> p3;
	p3.setX('a');
	p3.setY('b');
	
	cout << p3.getX() << " " << p3.getY() << endl;
	*/
	
	return 0;
}
