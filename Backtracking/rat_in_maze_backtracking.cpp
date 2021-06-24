#include<bits/stdc++.h>
using namespace std;

void printSolution(int** solution,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
}
void mazeHelper(int maze[20][20],int n,int** solution,int x,int y){
    if(x==n-1 && y==n-1){
        solution[x][y]=1;
        printSolution(solution,n);
        return;
    }
    if(x>=n || x<0 || y>=n || y<0 || maze[x][y]==0 || solution[x][y]==1){
        return;
    }
    solution[x][y]=1;
    //up
    mazeHelper(maze,n,solution,x-1,y); 
    //down 
    mazeHelper(maze,n,solution,x+1,y);  
    //left
    mazeHelper(maze,n,solution,x,y-1);
    //right
    mazeHelper(maze,n,solution,x,y+1);
    solution[x][y]=0;
}
void ratInMaze(int maze[20][20],int n){
    int** solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n];
    }
    //initialization of solution 2d array takes place
    for(int i=0; i<n; i++){
        memset(solution[i], 0, n*sizeof(int));
    }

    mazeHelper(maze,n,solution,0,0);
}
int main(){
    int n=0;
    cin>>n;
    int maze[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    cout<<endl;
    ratInMaze(maze,n);
    return 0;
}