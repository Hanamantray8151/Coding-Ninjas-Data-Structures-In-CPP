/*
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 
(both inclusive).
Print the elements in increasing order.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree 
is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an 
indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.
Output Format:
The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). Print the elements 
in increasing order.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output 1:
6 7 8 10
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

void elementsInRangeK1K2(BinaryTreeNode* root,int k1,int k2){
	if(root == NULL){
		return;
	}
	
	if(k1 < root -> data){
		elementsInRangeK1K2(root -> left,k1,k2);
	}
	
	if(k1 <= root -> data && k2 >= root -> data){
		cout << root -> data << " ";
	}
	
	if(k2 > root -> data){
		elementsInRangeK1K2(root -> right,k1,k2);
	}
}

int main(){
	BinaryTreeNode* root = takeinputLevelWise();
	int k1,k2;
	cin >> k1 >> k2;
	
	elementsInRangeK1K2(root,k1,k2);
	cout << endl;

	return 0;
}
