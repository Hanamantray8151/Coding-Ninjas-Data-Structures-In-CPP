/*
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/
#include<bits/stdc++.h>
using namespace std;

void printsubsetsHelper(int input[],int si,int n,int output[],int m){
	if(si == n){
		for(int i=0;i<m;i++){
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}
	int newoutput[1000];
	printsubsetsHelper(input,si + 1,n,output,m);
	int i = 0;
	for(i=0;i<m;i++){
		newoutput[i] = output[i];
	}
	newoutput[i] = input[si];
	printsubsetsHelper(input,si + 1,n,newoutput,m + 1);
}

void printSubsetsOfArray(int input[], int size) {
    int output[1000];
    int m = 0;
    printsubsetsHelper(input,0,size,output,m);
}

int main(){
	int input[20],length;
	cin >> length;
	for(int i=0;i<length;i++){
		cin >> input[i];
	}
	printSubsetsOfArray(input,length);
	return 0;
}
