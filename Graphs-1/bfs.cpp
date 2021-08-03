#include<bits/stdc++.h>
using namespace std;

void printBFS(int **edges,int n,int sv,bool *visited){
	queue<int> q;
	
	q.push(sv);	//starting vertex pushed into the queue.
	visited[sv] = true;
	
	while(!q.empty()){	//Check if queue is empty.
		int currVertex = q.front();
		cout << currVertex << endl;	//Print the current vertex.
		q.pop();	//Pop the current vertex after printing.
		
		for(int i=0;i<n;i++){	//Loop through the graph until n becomes equal to no of vertices.
			if(edges[currVertex][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void BFS(int **edges,int n){
	bool *visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printBFS(edges,n,i,visited);
		}
	}
	delete [] visited;
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
	
	BFS(edges,n);
	
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
	return 0;
}
