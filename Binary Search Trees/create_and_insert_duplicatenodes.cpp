/*
For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
The root will remain the same. So you just need to insert nodes in the given Binary Tree.
You can see that every node in the input tree has been duplicated and inserted to the left of itself.
Input format :
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an 
indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format :
The updated tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Note:
You are not required to print anything explicitly. It has already been taken care of. Just implement the function to 
achieve the desired structure of the tree.
Constraints :
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 1:
10 
10 30 
20 30 60 
20 50 60 
40 50 
40 
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 2:
8 
8 10 
5 10 
5 6 
2 6 7 
2 7
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

void insertDuplicateNode(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }

    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);

    BinaryTreeNode* path = root -> left;
    BinaryTreeNode* newNode = new BinaryTreeNode(root -> data);
    root -> left = newNode;
    newNode -> left = path;
}

void printTree(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    printTree(root -> left);
    printTree(root -> right);
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    root -> left = new BinaryTreeNode(20);
    root -> right = new BinaryTreeNode(30);
    root -> left -> left = new BinaryTreeNode(40);
    root -> left -> right = new BinaryTreeNode(50);
    root -> right -> left = new BinaryTreeNode(60);
    root -> right -> right = new BinaryTreeNode(70);

    insertDuplicateNode(root);
    printTree(root);
    return 0;
}
