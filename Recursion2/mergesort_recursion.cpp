/*
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/
#include<bits/stdc++.h>
using namespace std;

void merge(int input[], int s, int mid, int e){
    int temp[e - s + 1];
    int i = s;
    int j = mid + 1;
    //Let one part of array is from s to mid and another from mid+1 to end
    int k = 0;
    
    while(i<=mid && j<=e){
        if(input[i]<=input[j]){
            temp[k++] = input[i];
            i++;
        }
        else{
            temp[k++] = input[j];
            j++;
        }
    }
    while(i<=mid) {
        temp[k++] = input[i];
        i++;
    }
    while(j<=e) {
        temp[k++] = input[j];
        j++;
    }
    
    for(int i=s;i<=e;i++) {
        input[i] = temp[i-s];
    }
}

void mergeSort(int input[],int si,int ei){
	if(si >= ei){
		return;
	}
	int mid = (si + ei)/2;
	mergeSort(input,si,mid);
	mergeSort(input,mid + 1,ei);
	merge(input,si,mid,ei);
}

void mergeSort(int input[], int size){
	if(size == 0 || size == 1){
		return;
	}
	mergeSort(input,0,size-1);
}

int main(){
	int size;
	cin >> size;
	int input[size];
	for(int i=0;i<size;i++){
		cin >> input[i];
	}
	mergeSort(input,size);
	for(int i=0;i<size;i++){
		cout << input[i] << " ";
	}
	cout << endl;
	return 0;
}
