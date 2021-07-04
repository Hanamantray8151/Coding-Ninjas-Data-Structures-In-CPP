/*
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/
#include<bits/stdc++.h>
using namespace std;

void printSubsetSumToK(int input[],int si,int n,int k,int output[],int m){
	if(si == n){
		if(k == 0){
			for(int i=0;i<m;i++){
				cout << output[i] <<" ";
			}
			cout << endl;
			return;
		}else{
			return;
		}
	}
	int newoutput[50];
	printSubsetSumToK(input,si+1,n,k,output,m);
	int i=0;
	for(i=0;i<m;i++){
		newoutput[i] = output[i];
	}
	newoutput[i] = input[si];
	printSubsetSumToK(input,si+1,n,k-input[si],newoutput,m+1);
}

void printSubsetSumToK(int input[],int n,int k){
	int output[50];
	printSubsetSumToK(input,0,n,k,output,0);
}

int main(){
	int input[50],length,k;
	cin >> length;
	for(int i=0;i<length;i++){
		cin >> input[i];
	}
	cin >> k;
	printSubsetSumToK(input,length,k);
	return 0;
}
