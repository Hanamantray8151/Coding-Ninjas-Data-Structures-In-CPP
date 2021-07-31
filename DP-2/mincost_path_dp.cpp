/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell 
(0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. 
They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
*/

#include<bits/stdc++.h>
using namespace std;

/*int helper(int **arr,int m,int n,int row,int col){  //Recursive Brute Force Approach.
    //Base case.
    if(row == m - 1 && col == n - 1){
        return arr[row][col];
    }

    if(row >= m || col >= n){
        return INT_MAX;
    }

    //Recursive call to right.
    int x = helper(arr,m,n,row,col+1);
    //Recursive call to diagonal.
    int y = helper(arr,m,n,row+1,col+1);
    //Recursive call to down.
    int z = helper(arr,m,n,row+1,col);
    
    int ans = min(x,min(y,z)) + arr[row][col];

    return ans;
}

int minCostPath(int **arr,int m,int n){
    return helper(arr,m,n,0,0);
}*/

/*int helper(int **arr,int m,int n,int row,int col,int **output){ //Memoization approach.
    //Base case.
    if(row == m - 1 && col == n - 1){
        return arr[row][col];
    }

    if(row >= m || col >= n){
        return INT_MAX;
    }

    //Check if answer already exists.
    if(output[row][col] != -1){
        return output[row][col];
    }

    //Recursive call to right.
    int x = helper(arr,m,n,row,col+1,output);
    //Recursive call to diagonal.
    int y = helper(arr,m,n,row+1,col+1,output);
    //Recursive call to down.
    int z = helper(arr,m,n,row+1,col,output);
    
    int ans = min(x,min(y,z)) + arr[row][col];

    //Save the output for future use.
    output[row][col] = ans;
    return output[row][col];
}

int minCostPath(int **arr,int m,int n){
    int **output;
    output = new int *[m];
    for(int i=0;i<n;i++){
        output[i] = new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            output[i][j] = -1;
        }
    }
    return helper(arr,m,n,0,0,output);
}*/

int minCostPath(int **arr,int m,int n){ //Dp Approach.
    int **dp;
    dp = new int *[m];
    for(int i=0;i<m;i++){
        dp[i] = new int[n];
    }

    //Fill the last cell in the matrix.
    dp[m - 1][n - 1] = arr[m - 1][n - 1];

    //Fill the last row.
    for(int j=n-2;j>=0;j--){
        dp[m - 1][j] = dp[m - 1][j + 1] + arr[m - 1][j];  
    }

    //Fill the last column.
    for(int i=m-2;i>=0;i--){
        dp[i][n - 1] = dp[i + 1][n - 1] + arr[i][n - 1];
    }

    //Fill the remaining cells.
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j] = min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j])) + arr[i][j];
        }
    }
    return dp[0][0];
}

int main(){
    int **arr,m,n;
	  cin >> m >> n;
	  arr = new int *[m];
	  for (int i=0;i<m;i++){
		    arr[i] = new int[n];
	  }
	  for (int i=0;i<m;i++){
		    for (int j=0;j<n;j++){
			      cin >> arr[i][j];
		    }
	  }
	  cout << minCostPath(arr,m,n) << endl;

    return 0;
}
