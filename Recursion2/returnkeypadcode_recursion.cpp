/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include<bits/stdc++.h>
using namespace std;
string a[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num,string output[]){
	if(num == 0){
		output[0] = "";
		return 1;
	}
	int b = num%10;
	num = num/10;
	int count = keypad(num,output);
	for(int i=0;i<a[b-2].size()*count;i++){
		output[count + i] = output[i%count];
	}
	int i = 0;
	for(int j=0;j<a[b-2].size();j++){
		for(;i<count*(j+1);i++){
			output[i] = output[i] + a[b-2][j];
		}
	}
	return count*a[b-2].size();
}

int main(){
	int num;
	cin >> num;
	
	string output[10000];
	int count = keypad(num,output);
	for(int i=0;i<count;i++){
		cout << output[i] << endl;
	}
	return 0;
}
