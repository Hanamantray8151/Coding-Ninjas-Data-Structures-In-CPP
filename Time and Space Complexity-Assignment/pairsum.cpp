/*
You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements. 
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the first array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.
Third line contains an integer 'num'.
Output format :
For each test case, print the total number of pairs present in the array/list.
Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10
Sample Output 2:
0
2
Explanation for Input 2:
Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
*/

#include<bits/stdc++.h>
using namespace std;

int pairsum(int* a,int n,int num){
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] + a[j] == num){
				count++;
			}
		}
	}
	return count;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int size;
		cin >> size;
		int* input = new int[size];
		for(int i=0;i<size;i++){
			cin >> input[i];
		}
		int num;
		cin >> num;
		cout << endl;
		cout << pairsum(input,size,num) << endl;
		delete [] input;
	}
	return 0;
}
