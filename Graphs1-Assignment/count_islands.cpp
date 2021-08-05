/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach
from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections
or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 
*/

#include<bits/stdc++.h>
using namespace std;

int helper(int **edges,int n,int sv,bool *visited){
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	
	while(!q.empty()){
		int currVertex = q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(edges[currVertex][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return 1;
}

int countIslands(int **edges,int n){
	bool *visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	
	int ans = 0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			ans = ans + helper(edges,n,i,visited);
		}
	}
	return ans;
}

int main(){
	int n,e;
	cin >> n >> e;
	
	int **edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i] = new int[n];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			edges[i][j] = 0;
		}
	}
	
	for(int i=0;i<e;i++){
		int f,s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	
	cout << countIslands(edges,n) << endl;

	return 0;
}
