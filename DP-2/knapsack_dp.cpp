/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs
wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return
the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, 
that denote the values of weight of items. The following line contains N space separated integers, that denote the values 
associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight 
that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/

#include<bits/stdc++.h>
using namespace std;

/*int helper(int *weights,int *values,int n,int maxweight,int **output){ //Memoization approach.
    //Base case.
    if(n == 0 || maxweight == 0){
        return 0;
    }
    if(weights[0] > maxweight){
        return helper(weights+1,values+1,n - 1,maxweight,output);
    }

    //Check if answer already exists.
    if(output[n][n] != -1){
        return output[n][n];
    }

    int x = values[0] + helper(weights+1,values+1,n - 1,maxweight - weights[0],output);
    int y = helper(weights+1,values+1,n - 1,maxweight,output);

    output[n][n] = max(x,y);
    return output[n][n];
}

int knapsack(int *weights,int *values,int n,int maxweight){
    int **output;
    output = new int *[n + 1];
    for(int i=0;i<=n;i++){
        output[i] = new int[maxweight + 1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxweight;j++){
            output[i][j] = -1;
        }
    }
    return helper(weights,values,n,maxweight,output);
}*/

int knapsack(int *weights,int *values,int n,int maxweight){ //Dp approach.
    int **dp;
    dp = new int *[n + 1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[maxweight + 1];
    }

    //Fill the first row.
    for(int j=0;j<=maxweight;j++){
        dp[0][j] = 0;
    }

    //Fill the first column.
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
  
    /*  Without space optimization O(n*w).
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxweight;j++){
            if(weights[i - 1] > j){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j],values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
        }
    }
    */

    //Fill the remaining cells.
    int currrow = 0;  //With Space optimization O(w).
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxweight;j++){
            if(weights[i - 1] > j){
                dp[currrow ^ 1][j] = dp[currrow][j];
            }else{
                dp[currrow ^ 1][j] = max(dp[currrow][j],values[i - 1] + dp[currrow][j - weights[i - 1]]);
            }
        }
        currrow = currrow ^ 1;
    }
    return dp[currrow][maxweight];
}

int main(){
    int n;
    cin >> n;
    int *weights = new int[n];
    int *values = new int[n];

    for(int i=0;i<n;i++){
        cin >> weights[i];
    }
    for(int i=0;i<n;i++){
        cin >> values[i];
    }

    int maxweight;
    cin >> maxweight;

    cout << knapsack(weights,values,n,maxweight) << endl;

    delete [] weights;
    delete [] values;
    return 0;
}
