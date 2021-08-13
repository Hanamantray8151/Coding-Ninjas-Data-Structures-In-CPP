/*
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which 
contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree 
is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an 
indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
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

vector<Node*> constructLinkedListForEachLevel(BinaryTreeNode* root){
	vector<Node*> output;
	queue<BinaryTreeNode*> q;
	
	if(root == NULL){
		output.push_back(NULL);
		return output;
	}
	
	q.push(root);
	q.push(NULL);
	Node* head = NULL;
	Node* tail = NULL;
	
	while(!q.empty()){
		BinaryTreeNode* front = q.front();
		q.pop();
		
		if(front == NULL){
			if(q.empty()){
				break;
			}else{
				head = NULL;
				tail = NULL;
				q.push(NULL);
			}
		}else{
			Node *newNode = new Node(front -> data);
			if(head == NULL){
				head = newNode;
				tail = newNode;
				output.push_back(head);
			}else{
				tail -> next = newNode;
				tail = newNode;
			}
			
			if(front -> left != NULL){
				q.push(front -> left);
			}
			if(front -> right != NULL){
				q.push(front -> right);
			}
		}
	}
	return output;
}

void print(Node* head){
	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next; 
	}
	cout << endl;
}

//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

int main(){
	BinaryTreeNode* root = takeinputLevelwise();
	
	vector<Node*> output = constructLinkedListForEachLevel(root);
	
	for(int i=0;i<output.size();i++){
		print(output[i]);
	}
	
	return 0;
}
