/*
Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.
Note:
1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree 
is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an 
indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The updated binary tree, after removing leaf nodes, is printed level wise. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
8
3 10
6 14 
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

void printLevelWise(BinaryTreeNode* root){
	queue<BinaryTreeNode*> q;
	if(root == NULL){
		return;
	}
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		BinaryTreeNode* front = q.front();
		q.pop();
		if(front == NULL){
			if(q.empty()){
				return;
			}else{
				cout << endl;
				q.push(NULL);
			}
		}else{
			cout << front -> data << " ";
			if(front -> left != NULL){
				q.push(front -> left);
			}
			if(front -> right != NULL){
				q.push(front -> right);
			}
		}
	}
}

BinaryTreeNode* removeLeafNodes(BinaryTreeNode* root){
	if(root == NULL){
		return NULL;
	}
	
	if(root -> left == NULL && root -> right == NULL){
		free(root);
		return NULL;
	}else{
		root -> left = removeLeafNodes(root -> left);
		root -> right = removeLeafNodes(root -> right);
	}
	return root;
}

//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

int main(){
	BinaryTreeNode* root = takeinputLevelwise();
	
	BinaryTreeNode* finalroot = removeLeafNodes(root);
	printLevelWise(root);
	cout << endl;
	
	return 0;
}
