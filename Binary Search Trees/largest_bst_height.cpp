/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the 
given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree 
is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an 
indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
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

bool isBST(BinaryTreeNode* root,int min = INT_MIN,int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> data < min || root -> data > max){
        return false;
    }
    int isLeftOk = isBST(root -> left,min,root -> data - 1);
    int isRightOk = isBST(root -> right,root -> data,max);
    return isLeftOk && isRightOk;
}

int height(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    return max(leftHeight,rightHeight) + 1;
}

int largestBSTHeight(BinaryTreeNode* root){
    if(isBST(root)){
        return height(root);
    }else{
        int ans1 = largestBSTHeight(root -> left);
        int ans2 = largestBSTHeight(root -> right);
        return max(ans1,ans2);
    }
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root -> left = new BinaryTreeNode(10);
    root -> right = new BinaryTreeNode(6);
    root -> left -> left = new BinaryTreeNode(2);
    root -> left -> right = new BinaryTreeNode(3);
    root -> left -> right -> right = new BinaryTreeNode(9);

    cout << largestBSTHeight(root) << endl;
    return 0;
}
