/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/
#include<bits/stdc++.h>
using namespace std;

int getCodes(string input,string output[]){
	if(input.empty()){
		output[0] = "";
		return 1;
	}
	string o1[10000];
	string o2[10000];
	int i1 = input[0] - '0';
	char c1 = 'a' + i1 - 1;
	char c2 = '\0';
	int s1 = getCodes(input.substr(1),o1);
	int s2 = 0;
	if(input[1] != '\0'){
		int i2 = i1 * 10 + (input[1] - '0');
		if(i2 >= 0 && i2 <= 26){
			c2 = 'a' + i2 - 1;
		    s2 = getCodes(input.substr(2),o2);
		}
	}
	for(int i=0;i<s1;i++){
		output[i] = c1 + o1[i];
	}
	for(int i=0;i<s2;i++){
		output[s1 + i] = c2 + o2[i];
	}
	return s1 + s2;
}

int main(){
	string input;
	cin >> input;
	string output[10000];
	int count = getCodes(input,output);
	for(int i=0;i<count && i<10000;i++){
		cout << output[i] << endl;
	}
	return 0;
}
