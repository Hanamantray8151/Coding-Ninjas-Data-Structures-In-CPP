#include<bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char s[]){
	if(s[0] == '\0'){
		return;
	}
	removeConsecutiveDuplicates(s + 1);
	if(s[0] == s[1]){
		int i = 1;
		for(;s[i] != '\0';i++){
			s[i-1] = s[i];
		}
		s[i-1] = s[i];
	}
}

int main(){
	char str[1000];
	cin >> str;
	removeConsecutiveDuplicates(str);
	cout << str << endl;
	return 0;
}
