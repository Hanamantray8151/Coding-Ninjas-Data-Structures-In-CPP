#include<bits/stdc++.h>
using namespace std;

void removeX(char input[]) {
    if(input[0] == '\0'){
        return;
    }
    if(input[0] == 'x'){
        for(int i=0;input[i]!='\0';i++){
            input[i] = input[i+1];
        }
        removeX(input);
    }else{
        removeX(input+1);
    }
}
int main(){
    char input[100];
    cin.getline(input, 100);

    removeX(input);
    cout << input << endl;
    return 0;
}