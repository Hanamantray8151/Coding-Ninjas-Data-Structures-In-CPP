/*
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the first array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.
Third line contains an integer 'X'.
Output format :
For each test case, print the total number of triplets present in the array/list.
Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5
Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.
For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)
*/

#include<bits/stdc++.h>
using namespace std;

/*int tripletSum(int* a,int n,int num){		//O(n^3)
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i] + a[j] + a[k] == num){
					count++;
				}
			}
		}
	}
	return count;
}*/

int pairSum(int* a,int start,int end,int sum){			//O(n*logn)
	int numberOfPairs = 0;
	while(start < end){
		if(a[start] + a[end] < sum){
			start++;
		}else if(a[start] + a[end] > sum){
			end--;
		}else{								//a[i] + a[j] == sum
			int elementAtStart = a[start];
			int elementAtEnd = a[end];
			if(elementAtStart == elementAtEnd){
				int totalElementsFromStartToEnd = end - start + 1;
				numberOfPairs = numberOfPairs + (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1)/2);
				return numberOfPairs;
			}
			int tempStart = start + 1;
			int tempEnd = end - 1;
			while(tempStart <= tempEnd && a[tempStart] == elementAtStart){
				tempStart = tempStart + 1;
			}
			while(tempEnd >= tempStart && a[tempEnd] == elementAtEnd){
				tempEnd = tempEnd - 1;
			} 		
			int elementsFromStartToTempStart = tempStart - start;
			int elementsFromTempEndToEnd = end - tempEnd;
			numberOfPairs = numberOfPairs + (elementsFromStartToTempStart * elementsFromTempEndToEnd);
			start = tempStart;
			end = tempEnd;
		}
	}
	return numberOfPairs;
}

int tripletSum(int* a,int n,int num){
	sort(a,a + n);
	int count = 0;
	for(int i=0;i<n;i++){
		int pairSumFor = num - a[i];
		count = count + pairSum(a,i + 1,n - 1,pairSumFor);
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
		cout << tripletSum(input,size,num) << endl;
		delete [] input;
	}
	return 0;
}
