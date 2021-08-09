#include<bits/stdc++.h>
using namespace std;

int main(){
	unordered_map<string,int> ourmap;
	
	//Insert.
	ourmap["abc"] = 1;
	ourmap["def"] = 1;
	
	//Find or Access.
	cout << ourmap.at("abc") << endl;	//Using square brackets it gives the value if the key is present.
	cout << ourmap.at("def") << endl;	//Another way of accessing the key.
	
	//cout << ourmap["ghi"] << endl;	//If we try to access key with square bracket which is not present then by default it takes 0.
	//cout << ourmap.at("ghi") << endl;	//If we try to access key which is not present using at then it gives error.
		
	//Size.
	cout << ourmap.size() << endl;
	
	//Check if key is present or not.
	if(ourmap.count("abc") > 0){
		cout << "key is present" << endl;
	}else{
		cout << "key is not present" << endl;
	}
	
	//Erase.
	ourmap.erase("def");
	cout << ourmap.size() << endl;

	return 0;
}
