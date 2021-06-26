#include<bits/stdc++.h>
using namespace std;

int stringToInt(char input[]){
    int intvalue = atoi(input);
    return intvalue;
}

int main(){
    char input[50];
    cin>>input;
    cout<<stringToInt(input)<<endl;
    return 0;
}