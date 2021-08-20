/*
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output 
are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/

#include<bits/stdc++.h>
using namespace std;

void heapSort(int *input,int n){
    for(int i=1;i<n;i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(input[parentIndex] > input[childIndex]){
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int size = n;
    while(size > 1){
        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;
        size--;

        int parentIndex = 0;
        int leftchildIndex = (2 * parentIndex) + 1;
        int rightchildIndex = (2 * parentIndex) + 2;
        while(leftchildIndex < size){
            int minIndex = parentIndex;
            if(input[minIndex] > input[leftchildIndex]){
                minIndex = leftchildIndex;
            }
            if(rightchildIndex < size && input[minIndex] > input[rightchildIndex]){
                minIndex = rightchildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;

            parentIndex = minIndex;
            leftchildIndex = (2 * parentIndex) + 1;
            rightchildIndex = (2 * parentIndex) + 2;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
