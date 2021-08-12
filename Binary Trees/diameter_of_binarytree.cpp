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

pair<int,int> heightDiameter(BinaryTreeNode* root){
	if(root == NULL){
		pair<int,int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	
	pair<int,int> leftAns = heightDiameter(root -> left);
	pair<int,int> rightAns = heightDiameter(root -> right);
	
	int lh = leftAns.first;
	int ld = leftAns.second;
	int rh = rightAns.first;
	int rd = rightAns.second;
	
	int height = 1 + max(lh,rh);
	int diameter = max(lh + rh,max(ld,rd));
	
	pair<int,int> p;
	p.first = height;
	p.second = diameter;
	
	return p;	
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

//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

int main(){
	BinaryTreeNode* root = takeinputLevelwise();
	printTree(root);
	
	pair<int,int> p = heightDiameter(root);
	cout << "Height : " << p.first << endl;
	cout << "Diameter : " << p.second << endl;

	return 0;
}
