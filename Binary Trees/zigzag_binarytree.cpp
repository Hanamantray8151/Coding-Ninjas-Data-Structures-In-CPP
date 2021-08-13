/*
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right 
to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is 
separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication 
whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
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

void zigZagOrder(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
    stack<BinaryTreeNode*> firstStack;	//R -> L.
    stack<BinaryTreeNode*> secondStack;	//L -> R.
    
    firstStack.push(root);
    while(!firstStack.empty()){
    	BinaryTreeNode* top = firstStack.top();
    	cout << top -> data << " ";
    	firstStack.pop();
    	if(top -> left != NULL){
    		secondStack.push(top -> left);
    	}
    	if(top -> right != NULL){
    		secondStack.push(top -> right);
    	}
    	if(!firstStack.empty()){
    		continue;
    	}
    	cout << endl;
    	while(!secondStack.empty()){
    		BinaryTreeNode* top = secondStack.top();
    		cout << top -> data << " ";
    		secondStack.pop();
    		if(top -> right != NULL){
    			firstStack.push(top -> right);
    		}
    		if(top -> left != NULL){
    			firstStack.push(top -> left);
    		}
    	}
    	cout << endl;
    }
}		

//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

int main(){
	BinaryTreeNode* root = takeinputLevelwise();
	
	zigZagOrder(root);
	
	return 0;
}
