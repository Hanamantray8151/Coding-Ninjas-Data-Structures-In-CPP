#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n,char source,char auxiliary,char destination){
    if( n > 0){
	towerOfHanoi(n-1,source,destination,auxiliary);
    
	cout <<source<<" "<<destination<<endl;
    
	towerOfHanoi(n-1,auxiliary,source,destination);
    }
}

int main(){
    int n;
    char a,b,c;
    cin>>n;
    towerOfHanoi(n,'a','b','c');
    return 0;
}