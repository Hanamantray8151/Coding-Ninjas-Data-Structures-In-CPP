/*
Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, 
if node with data k is present, return false otherwise.
Note: Assume that BST contains all unique elements.
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree 
is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an 
indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format:
The first and only line of output contains a boolean value. Print true, if node with data k is present, print false otherwise. 
Constraints:
Time Limit: 1 second
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1 :
true
Sample Input 2 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 2 :
false
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
};

BinaryTreeNode* takeinputLevelWise(){
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

bool searchInBST(BinaryTreeNode* root,int x){
	if(root == NULL){
		return false;
	}
	
	if(root -> data == x){
		return true;
	}
	
	if(x < root -> data){
		return searchInBST(root -> left,x);
	}else{
		return searchInBST(root -> right,x);
	}
}

int main(){
	BinaryTreeNode* root = takeinputLevelWise();
	int x;
	cin >> x;
	
	cout << (searchInBST(root,x) ? "true" : "false") << endl;

	return 0;
}
