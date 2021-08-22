/*
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following contains an integer, that denotes the value of k.
Output Format :
The first and only line of output contains the kth largest element
Constraints :
1 <= N, Ai, k <= 10^5
Time Limit: 1 sec
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9
Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
*/

#include<bits/stdc++.h>
using namespace std;

int kthLargestElement(int *a,int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    for(int j=k;j<n;j++){
        if(pq.top() < a[j]){
            pq.pop();
            pq.push(a[j]);
        }
    }
    return pq.top();
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << kthLargestElement(arr,n,k) << endl;
    delete[] arr;
    return 0;
}
