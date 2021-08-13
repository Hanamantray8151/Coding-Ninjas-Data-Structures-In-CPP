/*
For a given Binary Tree of type integer, print all the nodes without any siblings.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an
indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the node data in a top to down fashion with reference to the root. 
Node data in the left subtree will be printed first and then the right subtree.
A single space will separate them all.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
9    
Sample Input 2:
2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
6 7
*/

#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
	public:
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		
		BinaryTreeNode(int data){
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
		
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
};

BinaryTreeNode* takeinputLevelwise(){
	queue<BinaryTreeNode*> q;
	int rootData;
	cin >> rootData;
	
	if(rootData == -1){
		return NULL;
	}
	
	BinaryTreeNode* root = new BinaryTreeNode(rootData);
	q.push(root);
	
	while(!q.empty()){
		BinaryTreeNode* front = q.front();
		q.pop();
		
		int leftChildData;
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode* child = new BinaryTreeNode(leftChildData);
			front -> left = child;
			q.push(child);
		}
		
		int rightChildData;
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode* child = new BinaryTreeNode(rightChildData);
			front -> right = child;
			q.push(child);
		}
	}
	return root;
}

void printNodesWithoutSibling(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	
	if(root -> left != NULL && root -> right != NULL){
		printNodesWithoutSibling(root -> left);
		printNodesWithoutSibling(root -> right);
	}else if(root -> left != NULL){
		cout << root -> left -> data << " ";
		printNodesWithoutSibling(root -> left);
	}else if(root -> right != NULL){
		cout << root ->right -> data << " ";
		printNodesWithoutSibling(root -> right);
	}
}

//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

int main(){
	BinaryTreeNode* root = takeinputLevelwise();
	
	printNodesWithoutSibling(root);
	cout << endl;
	
	return 0;
}
