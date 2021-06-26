#include<bits/stdc++.h>
using namespace std;

int length(char input[]){
    int len=0;
    for(int i=0;input[i]!='\0';i++){
        len++;
    }
    return  len;
}
void pairstar(char input[],int start){
    if(input[start] == '\0'){
        return;
    }
    pairstar(input,start+1);
    if(input[start] == input[start+1]){
        int len = length(input);
        input[len+1] = '\0';
        for(int i=len-1;i>=start+1;i--){
            input[i+1] = input[i];
        }
        input[start+1] = '*';
    }
}
void pairstar(char input[]){
    pairstar(input,0);
}
int main(){
    char input[100];
    cin.getline(input,100);
    pairstar(input);
    cout<<input<<endl;
    return 0;
}