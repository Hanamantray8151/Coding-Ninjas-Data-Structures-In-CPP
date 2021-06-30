#include<bits/stdc++.h>
using namespace std;

void printsubs(string input,string output){
	if(input.empty()){
		cout << output << endl;
		return;
	}
	printsubs(input.substr(1),output);
	printsubs(input.substr(1),output + input[0]);
}

int main(){
	string input;
	cin >> input;
	string output = "";
	printsubs(input,output);
	return 0;
}
