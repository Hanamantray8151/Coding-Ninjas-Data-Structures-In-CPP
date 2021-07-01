/*
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S
Output format :
'true' or 'false'
Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
*/
#include<bits/stdc++.h>
using namespace std;

bool checkAB(char input[],int s){
	if(input[s] == '\0'){
		return true;
	}
	if(input[s] != 'a'){
		return false;
	}
	if(input[s + 1] != '\0' && input[s + 2] != '\0'){
		if(input[s + 1] == 'b' && input[s + 2] == 'b'){
			return checkAB(input,s + 3);
		}
	}
	return checkAB(input,s + 1);
}

bool checkAB(char input[]){
	checkAB(input,0);
}

int main(){
	char input[100];
	cin >> input;
	bool ans = checkAB(input);
	if(ans){
		cout << "true" << endl;
	}else{
		cout << "false" << endl;
	}
	return 0;
}
