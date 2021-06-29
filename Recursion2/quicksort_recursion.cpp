/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/
#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int start,int end){
	int pivot = a[start];
	int count = 0;
	for(int i=start+1;i<=end;i++){
		if(a[i] <= pivot){
			count++;
		}
	}
	
	int pivotIndex = start + count;	//Index of Pivot Element
	
	int temp = a[start];		//swap first and pivotIndexes
	a[start] = a[pivotIndex];
	a[pivotIndex] = temp;
	
	int p = start,q = end;
	while(p <= pivotIndex && q >= pivotIndex){
		while(a[p] < pivot){	//for left side elements
			p++;
		}
		while(a[q] > pivot){	//for right side elements
			q--;
		}
		if(p < pivotIndex && q > pivotIndex){
			int temp = a[p];
			a[p] = a[q];
			a[q] = temp;
			p++;
			q--;
		}
	}
	return pivotIndex;
}

void quickSort(int input[],int start,int end){
	if(start >= end){
		return;
	}
	int pivotIndex = partition(input,start,end);
	quickSort(input,start,pivotIndex - 1);
	quickSort(input,pivotIndex + 1,end);
}

void quickSort(int input[],int size){
	if(size == 0 || size == 1){
		return;
	}
	quickSort(input,0,size - 1);
}

int main(){
	int n;
	cin >> n;
	int input[n];
	for(int i=0;i<n;i++){
		cin >> input[i];
	}
	quickSort(input,n);
	for(int i=0;i<n;i++){
		cout << input[i] << " ";
	}
	cout << endl;
	
	return 0;
}
