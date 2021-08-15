/*
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of 
the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used 
as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
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

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
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

Node* constructLinkedList(BinaryTreeNode* root){
    if(root == NULL){
        return NULL;
    }

    Node *firstRoot = new Node(root -> data);
    Node *leftSubTree = constructLinkedList(root -> left);
    if(leftSubTree == NULL){
        leftSubTree = firstRoot;
    }else{
        Node *temp = leftSubTree;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = firstRoot;
    }
    Node *rightSubTree = constructLinkedList(root -> right);
    if(rightSubTree == NULL){
        firstRoot -> next = NULL;
    }else{
        firstRoot -> next = rightSubTree;
    }
    return leftSubTree;
}

int main(){
    BinaryTreeNode* root = takeinputLevelwise();
    Node* head = constructLinkedList(root);

    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
	return 0;
}
