/*
Input : 
abc
cab
Output : 
2
*/

#include<bits/stdc++.h>
using namespace std;

/*int lcs(string s,string t){ //Recursive Brute force approach.
    //Base case.
    if(s.empty() || t.empty()){
        return 0;
    }

    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1),t.substr(1));
    }else{
        int a = lcs(s.substr(1),t);
        int b = lcs(s,t.substr(1));
        int c = lcs(s.substr(1),t.substr(1));
        return max(a,max(b,c));
    }
}*/

/*int lcs(string s,string t,int **output){ //Memoization approach.
    int m = s.length();
    int n = t.length();

    //Base case.
    if(s.empty() || t.empty()){
        return 0;
    }

    //Check if answer already exists.
    if(output[m][n] != -1){
        return output[m][n];
    }

    int ans;
    if(s[0] == t[0]){
        ans = 1 + lcs(s.substr(1),t.substr(1),output);
    }else{
        int a = lcs(s.substr(1),t,output);
        int b = lcs(s,t.substr(1),output);
        int c = lcs(s.substr(1),t.substr(1),output);
        ans = max(a,max(b,c));
    }

    //Save the answer for future use.
    output[m][n] = ans;
    return output[m][n];
}

int lcs(string s,string t){
    int m = s.length();
    int n = t.length();
    int **output;
    output = new int *[m + 1];
    for(int i=0;i<=m;i++){
        output[i] = new int[n + 1];
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            output[i][j] = -1;
        }
    }
    return lcs(s,t,output);
}*/

int lcs(string s,string t){ //Dp approach.
    int m = s.length();
    int n = s.length();
    int **dp;
    dp = new int *[m + 1];
    for(int i=0;i<=m;i++){
        dp[i] = new int[n + 1];
    }

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = -1;
        }
    }

    //Fill the first cell.
    dp[0][0] = 0;

    //Fill the first column.
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }

    //Fill the first row.
    for(int j=0;j<=n;j++){
        dp[0][j] = 0;
    }

    //Fill the remaining cells.
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m - i] == t[n - j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j],max(dp[i][j - 1],dp[i - 1][j - 1]));
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;

    cout << lcs(s,t) << endl;

    return 0;
}
