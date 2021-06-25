#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int op1 = fibonacci(n-1);
    int op2 = fibonacci(n-2);
    return op1+op2;
}
int main(){
    cout<<fibonacci(4)<<endl;
    return 0;
}