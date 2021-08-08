/*
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, 
then the trees are called identical.  
Input format :
The first line of input contains data of the nodes of the first tree in level order form. The order is: data for root node, 
number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of 
the tree is separated by space.  
The following line of input contains data of the nodes of the second tree in level order form. The order is: data for root 
node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes
of the tree is separated by space.
Output format :
The first and only line of output contains true, if the given trees are structurally identical and false, otherwise.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0
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
	int rootData;
	cin >> rootData;
	
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty()){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
		int numofchild;
		cin >> numofchild;
		
		for(int i=0;i<numofchild;i++){
			int childData;
			cin >> childData;
			
			TreeNode<int>* child = new TreeNode<int>(childData);
			front -> children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

bool areIdentical(TreeNode<int>* root1,TreeNode<int>* root2){
	if(root1 == NULL && root2 == NULL){
		return true;
	}
	if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)){
		return false;
	}
	if((root1 -> data != root2 -> data) || (root1 -> children.size() != root2 -> children.size())){
		return false;
	}
	
	int i=0;
	while(i < root1 -> children.size()){
		TreeNode<int>* child1 = root1 -> children[i];
		TreeNode<int>* child2 = root2 -> children[i];
		
		if(child1 -> data == child2 -> data){
			i++;
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	TreeNode<int>* root1 = takeinput();
	TreeNode<int>* root2 = takeinput();
	
	cout << (areIdentical(root1,root2) ? "true" : "false") << endl;

	return 0;
}
