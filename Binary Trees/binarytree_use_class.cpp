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

BinaryTreeNode* takeinput(){
	int rootData;
	cout << "Enter Data : ";
	cin >> rootData;
	
	if(rootData == -1){
		return NULL;
	}
	
	BinaryTreeNode* root = new BinaryTreeNode(rootData);
	BinaryTreeNode* leftChild = takeinput();
	BinaryTreeNode* rightChild = takeinput();
	root -> left = leftChild;
	root -> right = rightChild;
	
	return root;
}

BinaryTreeNode* takeinputLevelwise(){
	queue<BinaryTreeNode*> q;
	int rootData;
	cout << "Enter root data" << endl;
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
		cout << "Enter left child of " << front -> data << endl;
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode* child = new BinaryTreeNode(leftChildData);
			front -> left = child;
			q.push(child);
		}
		
		int rightChildData;
		cout << "Enter right child of " << front -> data << endl;
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode* child = new BinaryTreeNode(rightChildData);
			front -> right = child;
			q.push(child);
		}
	}
	return root;
}

void printTree(BinaryTreeNode* root){
	if(root == NULL){
		return;
	}
	cout << root -> data << ":";
	if(root -> left != NULL){
		cout << "L" << root -> left -> data;
	}
	if(root -> right != NULL){
		cout << "R" << root -> right -> data;
	}
	cout << endl;
	printTree(root -> left);
	printTree(root -> right);
}

void printTreeLevelwise(BinaryTreeNode* root){
	queue<BinaryTreeNode*> q;
	
	if(root == NULL){
		return;
	}
	q.push(root);
	
	while(!q.empty()){
		BinaryTreeNode* front = q.front();
		q.pop();
		
		cout << front -> data << ":";
		if(front -> left != NULL){
			cout << "L:" << front -> left -> data << ",";
			q.push(front -> left);
		}else{
			cout << "L:" << "-1" << ",";
		}
		
		if(front -> right != NULL){
			cout << "R:" << front -> right -> data;
			q.push(front -> right);
		}else{
			cout << "R:" << "-1";
		}
		cout << endl;
	}
}

int main(){
	/*BinaryTreeNode* root = new BinaryTreeNode(1);
	BinaryTreeNode* node1 = new BinaryTreeNode(2);
	BinaryTreeNode* node2 = new BinaryTreeNode(3);
	root -> left = node1;
	root -> right = node2;*/
	
	//BinaryTreeNode* root = takeinput();
	//printTree(root);
	
	BinaryTreeNode* root = takeinputLevelwise();
	printTreeLevelwise(root);

	return 0;
}
