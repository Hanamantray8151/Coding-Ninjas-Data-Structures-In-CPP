/*
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/
#include<bits/stdc++.h>
using namespace std;

int returnPermutation(string input,string output[]){
	if(input.empty()){
		output[0] = "";
		return 1;
	}
	int k = 0;
	for(int i=0;i<input.size();i++){
		string smallOutput[1000];
		int ans = returnPermutation(input.substr(0,i) + input.substr(i+1,input.size()-i-1),smallOutput);
		for(int j=0;j<ans;j++){
			output[k] = input[i] + smallOutput[j];
			k++;
		}
	}
	return k;
}

int main(){
	string input;
	cin >> input;
	string output[10000];
	int count = returnPermutation(input,output);
	for(int i=0;i<count;i++){
		cout << output[i] << endl;
	}
	return 0;
}
