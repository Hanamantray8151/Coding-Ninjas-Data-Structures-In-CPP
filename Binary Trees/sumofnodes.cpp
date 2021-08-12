/*
For a given Binary Tree of integers, find and return the sum of all the nodes data.
Example:
                        10
                      /    \
                    20     30
                  /    \
                 40    50

When we sum up all the nodes data together, [10, 20, 30, 40 50] we get 150. Hence, the output will be 150.
Input Format:
The first and the only line of input will contain the nodes data, all separated by a single space. Since -1 is used as an 
indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The first and the only line of output prints the sum of all the nodes data present in the binary tree.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
2 3 4 6 -1 -1 -1 -1 -1
Sample Output 1:
 15
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
 28
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

int getSum(BinaryTreeNode* root){
	if(root == NULL){
		return 0;
	}
	
	int leftSum = getSum(root -> left);
	int rightSum = getSum(root -> right);
	
	return root -> data + leftSum + rightSum;
}

//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

int main(){
	BinaryTreeNode* root = takeinputLevelwise();
	
	cout << getSum(root) << endl;

	return 0;
}
