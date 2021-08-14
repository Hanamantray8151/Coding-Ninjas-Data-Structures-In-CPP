/*
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from 
this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated 
integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.
Constraints:
Time Limit: 1 second
Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7 
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

BinaryTreeNode* helper(int *input,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return NULL;
	}
	int mid = (startIndex + endIndex) / 2;
	BinaryTreeNode* root = new BinaryTreeNode(input[mid]);
	
	root -> left = helper(input,startIndex,mid - 1);
	root -> right = helper(input,mid + 1,endIndex);
	return root;
}

BinaryTreeNode* constructTree(int *input,int n){
	int startIndex = 0;
	int endIndex = n - 1;
	return helper(input,startIndex,endIndex);
}

void preOrder(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	
	cout << root -> data << " ";
	preOrder(root -> left);
	preOrder(root -> right);
}

int main(){
	int n;
	cin >> n;
	int *input = new int[n];
	
	for(int i=0;i<n;i++){
		cin >> input[i];
	}
	
	BinaryTreeNode* root = constructTree(input,n);
	
	preOrder(root);
	cout << endl;
	
	return 0;
}
