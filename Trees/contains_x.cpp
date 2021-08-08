/*
Given a generic tree and an integer x, check if x is present in the given tree or not. 
Return true if x is present, return false otherwise.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, data of each of child nodes 
and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x.
Output format :
The first and only line of output contains true, if x is present and false, otherwise.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
40 
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
4 
Sample Output 2:
false
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data){
			this -> data = data;
		}
};

TreeNode<int>* takeinput(){
	queue<TreeNode<int>*> q;

	int rootData;
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	q.push(root);
	
	while(!q.empty()){
		TreeNode<int>* front = q.front();
		q.pop();
	
		int numofchild;
		cin >> numofchild;
		
		for(int i=0;i<numofchild;i++){
			int childData;
			cin >> childData;
			
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}

bool containsX(TreeNode<int>* root,int x){
	queue<TreeNode<int>*> q;
	q.push(root);
	
	while(!q.empty()){
		TreeNode<int>* front = q.front();
		q.pop();
		if(front -> data == x){
			return true;
		}
		for(int i=0;i<front->children.size();i++){
			q.push(front->children[i]);
		}
	}
	return false;
}

int main(){
	TreeNode<int>* root = takeinput();
	int x;
	cin >> x;
	
	bool ans = containsX(root,x);
	
	if(ans){
		cout << "true" << endl;
	}else{
		cout << "false" << endl;
	}

	return 0;
}
