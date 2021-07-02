/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
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
#include<string.h>
using namespace std;

void printAllCodesHelper(string input,string output){
	if(input.empty()){
		cout << output << endl;
		return;
	}
	int i = input[0] - '0';
	char c = 'a' + i - 1;
	printAllCodesHelper(input.substr(1),output + c);
	if(input[1] != '\0'){
		i = i * 10 + (input[1] - '0');
		if(i >= 0 && i <=26){
			char c = 'a' + i - 1;
			printAllCodesHelper(input.substr(2),output + c);
		}
	}
}

void printAllCodes(string input){
	printAllCodesHelper(input,"");
}

int main(){
	string input;
	cin >> input;
	printAllCodes(input);
	return 0;
}
