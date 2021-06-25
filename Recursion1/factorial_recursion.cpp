#include<iostream>
using namespace std;

int fact(int n){
    cout<<n<<endl;
    if(n==0){
        return 1;
    }
    int smalloutput = fact(n-1);
    return n*smalloutput;
}
int main(){
    int n;
    cout<<"Enter Number To find Factorial"<<endl;
    cin>>n;
    int output = fact(n);
    cout<<output<<endl;
    return 0;
}
