/*
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order 
to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
Explanation to the Sample Input 1 :
In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. 
This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/

#include<bits/stdc++.h>
using namespace std;

/*int editDistance(string s1,string s2){  //Recursive brute force approach.
    //Base case.
    if(s1.empty() && s2.empty()){
        return 0;
    }
    if(s1.empty()){
        return s2.length();
    }
    if(s2.empty()){
        return s1.length();
    }
    
    if(s1[0] == s2[0]){
        int w = editDistance(s1.substr(1),s2.substr(1));
        return w;
    }else{
        int x = editDistance(s1.substr(1),s2);  //Insert.
        int y = editDistance(s1,s2.substr(1));  //Remove.
        int z = editDistance(s1.substr(1),s2.substr(1));  //Replace.
        int ans = min(x,min(y,z));
        return ans + 1;
    }
}*/

/*int helper(string s1,string s2,int **output){  //Memoization approach.
    int m = s1.length();
    int n = s2.length();
    //Base case.
    if(s1.empty() && s2.empty()){
        return 0;
    }
    if(s1.empty()){
        return s2.length();
    }
    if(s2.empty()){
        return s1.length();
    }
    
    //Check if answer already exists.
    if(output[m][n] != -1){
        return output[m][n];
    }

    int ans;
    if(s1[0] == s2[0]){
        ans = helper(s1.substr(1),s2.substr(1),output);
    }else{
        int x = helper(s1.substr(1),s2,output) + 1;  //Insert.
        int y = helper(s1,s2.substr(1),output) + 1;  //Remove.
        int z = helper(s1.substr(1),s2.substr(1),output) + 1;  //Replace.
        ans = min(x,min(y,z));
    }
    //Save the answer for future use.
    output[m][n] = ans;
    return output[m][n];
}

int editDistance(string s1,string s2){
    int m = s1.length();
    int n = s2.length();
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
    return helper(s1,s2,output);
}*/

int editDistance(string s1,string s2){  //Dp approach.
    int m = s1.length();
    int n = s2.length();
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
    for(int i=1;i<=m;i++){
        dp[i][0] = i;
    }

    //Fill the first row.
    for(int j=1;j<=n;j++){
        dp[0][j] = j;
    }

    //Fill the remaining cells.
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m - i] == s2[n - j]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = min(dp[i - 1][j],min(dp[i][j - 1],dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s,t;
    cin >> s;
    cin >> t;
    cout << editDistance(s,t) << endl;

    return 0;
}
