/*
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
Input Format:
The first line of each test case contains elements of the first tree in the level order form. The line consists of values
of nodes separated by a single space. In case a node is null, we take -1 in its place.

The second line of each test case contains the node value you have to find.

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1
Explanation:
Level 1:
The root node of the tree is 1

Level 2:
Left child of 1 = 2
Right child of 1 = 3

Level 3:
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4:
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5:
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. 
The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current 
level and so on.
The input ends when all nodes at the last level are null(-1).
Note:
The above format was just to provide clarity on how the input is formed for a given tree.
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, 
the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
The only line of output prints 'true' or 'false'.

The output of each test case should be printed in a separate line.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5

Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7
Sample Output 1:
true
Explanation For Output 1:
Clearly, we can see that 7 is present in the tree. So, the output will be true.
Sample Input 2:
2 3 4 -1 -1 -1 -1
10
Sample Output 2:
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

bool findNode(BinaryTreeNode* root,int x){
	if(root == NULL){
		return false;
	}
	if(root -> data == x){
		return true;
	}
	bool leftsearch = findNode(root -> left,x);		//Seacrh x in the left subtree.
	bool rightsearch = findNode(root -> right,x);	//Search x in the right subtree.
	return leftsearch || rightsearch;
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
	int x;
	cin >> x;
	
	cout << (findNode(root,x) ? "true" : "false") << endl;
	
	return 0;
}
