/*
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.

Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)

Output Format :
Updated string

Constraints :
1 <= Length of String S <= 10^6

Sample Input :
abacd
a x

Sample Output :
xbxcd
*/
#include<bits/stdc++.h>
using namespace std;

void replaceCharacter(char s[],char c1,char c2){
	if(s[0] == '\0'){
		return;
	}
	if(s[0] != c1){
		replaceCharacter(s + 1,c1,c2);
	}else{
		for(int i=0;s[i] != '\0';i++){
			if(s[i] == c1){
				s[i] = c2;
			}
		}
		replaceCharacter(s,c1,c2);
	}
}

int main(){
	char input[1000000];
	char c1,c2;
	cin >> input;
	cin >> c1 >> c2;
	replaceCharacter(input, c1, c2);
	cout << input << endl;
	return 0;
}
