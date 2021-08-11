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

void inOrder(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	inOrder(root -> left);
	cout << root -> data << " ";
	inOrder(root -> right);
}

void preOrder(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	cout << root -> data << " ";
	preOrder(root -> left);
	preOrder(root -> right);
}

void postOrder(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	postOrder(root -> left);
	postOrder(root -> right);
	cout << root -> data << " ";
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
	
	cout << "Inorder Traversal : ";
	inOrder(root);
	cout << endl;
	
	cout << "Preoder Traversal : ";
	preOrder(root);
	cout << endl;
	
	cout << "Postoder Traversal : ";
	postaOrder(root);
	cout << endl;
	
	return 0;
}
