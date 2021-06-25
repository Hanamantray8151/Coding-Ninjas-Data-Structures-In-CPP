/*
Write a recursive function that returns the sum of the digits of a given integer.

Input format :
Integer N

Output format :
Sum of digits of N

Constraints :
0 <= N <= 10^9

Sample Input 1 :
12345

Sample Output 1 :
15

Sample Input 2 :
9

Sample Output 2 :
9
*/
#include<iostream>
using namespace std;

int sum(int input[], int n) {
    if(n==0){
        return 0;
    }
    int outputsum = sum(input+1,n-1);
    int arraysum = input[0]+outputsum;
    return arraysum;

}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << sum(input, n) << endl;
}
