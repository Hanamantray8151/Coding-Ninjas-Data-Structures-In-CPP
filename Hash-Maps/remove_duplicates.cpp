#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(int *a,int n){
	vector<int> output;
	unordered_map<int,bool> seenNumber;
	
	for(int i=0;i<n;i++){
		if(seenNumber.count(a[i]) > 0){
			continue;
		}
		seenNumber[a[i]] = true;
		output.push_back(a[i]);
	}
	return output;
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	vector<int> output = removeDuplicates(arr,n);
	for(int i=0;i<output.size();i++){
		cout << output[i] << " ";
	}
	cout << endl;

	delete [] arr;
	return 0;
}
