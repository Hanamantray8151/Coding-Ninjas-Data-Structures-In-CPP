/*
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present 
in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is 
separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication 
whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the nodes 
is separated by single space.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8
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

vector<int>* getRootToNodePath(BinaryTreeNode* root,int x){
    if(root == NULL){
        return NULL;
    }
    if(root -> data == x){
        vector<int>* output = new vector<int>();
        output -> push_back(root -> data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root -> left,x);
    if(leftOutput != NULL){
        leftOutput -> push_back(root -> data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root -> right,x);
    if(rightOutput != NULL){
        rightOutput -> push_back(root -> data);
        return rightOutput;
    }else{
        return NULL;
    }
}

int main(){
    BinaryTreeNode* root = takeinputLevelwise();

    int x;
    cin >> x;
    vector<int>* output = getRootToNodePath(root,x);
    for(int i=0;i<output->size();i++){
        cout << output -> at(i) << " ";
    }
    cout << endl;

	return 0;
}
