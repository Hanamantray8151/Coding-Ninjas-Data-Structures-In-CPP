/*
For a given Binary Tree of integers, find and return the height of the tree.
Example:
                        10
                      /    \
                    20      30
                  /    \
                 40    50

Height of the given tree is 3. 

Height is defined as the total number of nodes along the longest path from the root to any of the leaf node.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used 
as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The first and the only line of output prints the height of the given binary tree.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
0 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
10 20 30 40 50 -1 -1 -1 -1 -1 -1
Sample Output 1:
3
Sample Input 2:
3 -1 -1
Sample Output 2:
1
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

int height(BinaryTreeNode* root){
	if(root == NULL){
		return 0;
	}
	
	int leftHeight = height(root -> left);
	int rightHeight = height(root -> right);
	int maximum = max(leftHeight,rightHeight);
	return maximum + 1;
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
	
	cout << height(root) << endl;
	
	return 0;
}
