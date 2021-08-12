/*
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree
using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total 
number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
2 9 3 6 10 5 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
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
	cout << "Enter root data" << endl;
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
		cout << "Enter left child of " << front -> data << endl;
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode* child = new BinaryTreeNode(leftChildData);
			front -> left = child;
			q.push(child);
		}
		
		int rightChildData;
		cout << "Enter right child of " << front -> data << endl;
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode* child = new BinaryTreeNode(rightChildData);
			front -> right = child;
			q.push(child);
		}
	}
	return root;
}

BinaryTreeNode* buildTreeHelper(int *in,int *post,int inS,int inE,int postS,int postE){
	if(inS > inE){
		return NULL;
	}
	int rootData = post[postE];
	int rootIndex = -1;
	for(int i=inS;i<=inE;i++){
		if(in[i] == rootData){
			rootIndex = i;
			break;
		}
	}
	
	int linS = inS;
	int linE = rootIndex - 1;
	int lpostS = postS;
	int lpostE = linE - linS + lpostS;
	int rinS = rootIndex + 1;
	int rinE = inE;
	int rpostS = lpostE + 1;
	int rpostE = postE - 1;
	
	BinaryTreeNode* root = new BinaryTreeNode(rootData);
	
	root -> left = buildTreeHelper(in,post,linS,linE,lpostS,lpostE);
	root -> right = buildTreeHelper(in,post,rinS,rinE,rpostS,rpostE);
	return root;
}

BinaryTreeNode* buildTree(int *in,int *post,int size){
	return buildTreeHelper(in,post,0,size - 1,0,size - 1);
}

void printTree(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	cout << root -> data << ":";
	if(root -> left != NULL){
		cout << "L" << root -> left -> data;
	}
	if(root -> right != NULL){
		cout << "R" << root -> right -> data;
	}
	cout << endl;
	printTree(root -> left);
	printTree(root -> right);
}

int main(){
	int a[] = {4,2,5,1,6,3,7};
	int b[] = {4,5,2,6,7,3,1};
	
	BinaryTreeNode* root = buildTree(a,b,7);
	printTree(root);

	return 0;
}
