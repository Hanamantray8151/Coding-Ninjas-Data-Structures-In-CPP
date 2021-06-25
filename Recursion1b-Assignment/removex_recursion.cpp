/*
Given a string, compute recursively a new string where all 'x' chars have been removed.

Input format :
String S

Output format :
Modified String

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 

Sample Input 1 :
xaxb

Sample Output 1:
ab

Sample Input 2 :
abc

Sample Output 2:
abc

Sample Input 3 :
xx

Sample Output 3:

*/
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
