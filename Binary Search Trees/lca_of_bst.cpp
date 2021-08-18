/*
Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
Note:
1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is 
separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication 
whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains two integers, denoting the value of data of two nodes of given BST.
Output Format:
The first and only line of output contains the data associated with the lowest common ancestor node.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10
Sample Output 1:
8
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78
Sample Output 3:
-1
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

int LCAofBST(BinaryTreeNode* root,int n1,int n2){
    if(root == NULL){
        return -1;
    }
    if(root -> data == n1 || root -> data == n2){
        return root -> data;
    }else if(root -> data > n1 && root -> data > n2){
        return LCAofBST(root -> left,n1,n2);
    }else if(root -> data < n1 && root -> data < n2){
        return LCAofBST(root -> right,n1,n2);
    }else{
        int leftans = LCAofBST(root -> left,n1,n2);
        int rightans = LCAofBST(root -> right,n1,n2);
        if(leftans == -1 && rightans == -1){
            return -1;
        }else if(leftans != -1 && rightans == -1){
            return leftans;
        }else if(leftans == -1 && rightans != -1){
            return rightans;
        }else{
            return root -> data;
        }
    }
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(4);
    root -> left = new BinaryTreeNode(2);
    root -> right = new BinaryTreeNode(6);
    root -> left -> left = new BinaryTreeNode(1);
    root -> left -> right = new BinaryTreeNode(3);
    root -> right -> left = new BinaryTreeNode(5);
    root -> right -> right = new BinaryTreeNode(7);

    int a,b;
    cin >> a >> b;

    cout << LCAofBST(root,a,b) << endl;
    return 0;
}
