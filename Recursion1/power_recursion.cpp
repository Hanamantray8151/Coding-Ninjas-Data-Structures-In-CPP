#include<iostream>
using namespace std;

int power(int x,int n){
    if(n==0){
        return 1;
    }
    int output = power(x,n-1);
    return x*output;
}
int main(){
    int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<endl;
    return 0;
}