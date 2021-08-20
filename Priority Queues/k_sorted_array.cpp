#include<bits/stdc++.h>
using namespace std;

void kSortedArray(int input[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){   //Push first k elements into the priority queue.
        pq.push(input[i]);
    }

    int j = 0;  //Determines the element to this index.
    for(int i=k;i<n;i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }           //After this for loop our n - k array is sorted.

    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int a[] = {12,15,7,4,9};
    int k = 3;
    kSortedArray(a,5,k);

    for(int i=0;i<5;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
