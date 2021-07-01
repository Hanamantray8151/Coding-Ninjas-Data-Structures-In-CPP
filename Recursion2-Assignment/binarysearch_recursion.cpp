/*
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
*/
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int s,int e,int ele){
	if(s <= e){
		int mid = (s + e)/2;
		if(a[mid] == ele){
			return mid;
		}
		if(a[mid] > ele){
			return binarySearch(a,s,mid-1,ele);
		}
		if(a[mid] < ele){
			return binarySearch(a,mid+1,e,ele);
		}
	}
	return -1;
}

int binarySearch(int a[],int n,int ele){
	binarySearch(a,0,n-1,ele);
}

int main(){
	int size,input[100000],element;
	cin >> size;
	for(int i=0;i<size;i++){
		cin >> input[i];
	}
	cin >> element;
	cout << binarySearch(input,size,element) << endl;;
	
	return 0;
}
