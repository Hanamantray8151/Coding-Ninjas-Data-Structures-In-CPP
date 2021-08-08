#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data){
			this -> data = data;
		}
};

TreeNode<int>* takeinput(){
	int rootData;
	cout << "Enter Root Data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty()){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
		int numofchild;
		cout << "Enter no of children of " << front -> data << endl;
		cin >> numofchild;
		
		for(int i=0;i<numofchild;i++){
			int childData;
			cout << "Enter " << i << "th child of " << front -> data << endl;
			cin >> childData;
			
			TreeNode<int>* child = new TreeNode<int>(childData);
			front -> children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void preOrder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout << root -> data << " ";
	for(int i=0;i<root->children.size();i++){
		preOrder(root->children[i]);
	}
}

void postOrder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	for(int i=0;i<root->children.size();i++){
		postOrder(root->children[i]);
	}
	cout << root -> data << " ";
}

int main(){
	TreeNode<int>* root = takeinput();
	
	preOrder(root);
	cout << endl;
	
	postOrder(root);
	cout << endl;
	
	return 0;
}
