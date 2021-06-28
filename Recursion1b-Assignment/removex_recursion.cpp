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

void removeX(char s[]){
	if(s[0] == '\0'){
		return;
	}
	if(s[0] != 'x'){
		removeX(s + 1);
	}else{
		int i = 1;
		for(;s[i] != '\0';i++){
			s[i-1] = s[i];
		}
		s[i-1] = s[i];
		removeX(s);
	}
}

int main(){
	char str[100];
	cin >> str;
	removeX(str);
	cout << str <<endl;
	return 0;
}
