/*
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest 
numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.
Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space. 
Constraints:
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> kSmallestElements(int input[],int n,int k){
    priority_queue<int> pq;
    vector<int> v;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    for(int i=k;i<n;i++){
        if(input[i] < pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }

    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}

int main(){
    int a[] = {8,5,12,10,0,1,6,9};
    int k = 4;
    vector<int> output = kSmallestElements(a,8,k);
    sort(output.begin(),output.end());
    for(int i=0;i<output.size();i++){
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
