/*
For a given Binary Tree of type integer, update it with its corresponding mirror image.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used 
as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the mirrored tree in a level-wise order. 
Each level will be printed on a new line. Elements printed at each level will be separated by a single line.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 
3 2 
7 6 5 4
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 2:
5 
6 10 
3 2 
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

void mirrorBinaryTree(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	
	mirrorBinaryTree(root -> left);
	mirrorBinaryTree(root -> right);
	
	BinaryTreeNode* swapNode;
	swapNode = root -> left;
	root -> left = root -> right;
	root -> right = swapNode;
}

void printLevelAtNewLine(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	queue<BinaryTreeNode*> q;
	q.push(root);
	
	while(!q.empty()){
		BinaryTreeNode* front = q.front();
		q.pop();
		
		cout << front -> data << " ";
		if(front -> left != NULL){
			q.push(front -> left);
		}
		if(front -> right != NULL){
			q.push(front -> right);
		}
	}
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

int main(){
	/*BinaryTreeNode* root = new BinaryTreeNode(1);
	BinaryTreeNode* node1 = new BinaryTreeNode(2);
	BinaryTreeNode* node2 = new BinaryTreeNode(3);
	root -> left = node1;
	root -> right = node2;*/
	
	//BinaryTreeNode* root = takeinput();
	//printTree(root);
	
	BinaryTreeNode* root = takeinputLevelwise();
	
	mirrorBinaryTree(root);
	printLevelAtNewLine(root);
	cout << endl;
	
	return 0;
}
