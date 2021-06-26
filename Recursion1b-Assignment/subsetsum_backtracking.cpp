#include<bits/stdc++.h>
using namespace std;

int countSubsets(int arr[],int n,int k){
    // Base Case
    if(n == 0){
        
        // if k has become zero => We got a subset
        if(k == 0){
            return 1;
        }else{
            return 0;
        }
    }
    // Currently I am making the decision for the last element in the array (indexed n - 1)
    
    // First Option
    // choosing it in the subset
    // if we have choosen this in our subset, Now we want  subsets having sum = k - arr[n-1]
    // in the remaining array
    int option1 = countSubsets(arr, n - 1, k - arr[n-1]);
    
    // Second Option
    // Not choosing it in the subset
    // if we have not choosen this in our subset, Now we want  subsets having sum = k
    // in the remaining array
    
    int option2 = countSubsets(arr, n - 1, k);

    // either option1 will occur or option 2, So we simply add them and return
    return option1 + option2;
}
void solve(){
	
    int n; // sizeOfArray
    cin >> n;
    int k; // subsetSum
    cin >> k;
    // input
    int arr[n];
    for(int i =0;i < n;i++){
        cin >> arr[i];
    }

    int ans = countSubsets(arr, n, k); // count subsets of arr of size n having sum = k 
 	cout << ans << endl;   
}


int main(){
    int t; // testCases
    cin >> t;
    for(int i = 0;i < t;i++){
        solve();
    }
    return 0;
}