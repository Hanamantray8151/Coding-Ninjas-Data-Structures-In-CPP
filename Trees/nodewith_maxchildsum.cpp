/*
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. 
In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node,
number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes 
of the tree is separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
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

TreeNode<int>* maxSumNode(TreeNode<int>* root){
	queue<TreeNode<int>*> q;
	stack<TreeNode<int>*> s;
	
	q.push(root);
	
	int large = 0;
	while(!q.empty()){
		int maxSum = q.front() -> data;
		for(int i=0;i<root->children.size();i++){
			q.push(root->children[i]);
			maxSum = maxSum + root->children[i]->data;
		}
		if(maxSum > large){
			s.push(q.front());
			large = maxSum;
		}
		q.pop();
		root = q.front();
	}
	return s.top();
}

int main(){
	TreeNode<int>* root = takeinput();
	
	TreeNode<int>* ans = maxSumNode(root);
	
	if(ans != NULL){
		cout << ans -> data << endl;
	}

	return 0;
}
