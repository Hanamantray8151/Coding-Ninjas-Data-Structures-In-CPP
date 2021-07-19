#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int data){
			this -> data = data;
			this -> next = NULL;
		}
};

Node* takeinput(){
	int data;
	cin >> data;
	
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1){
		Node *newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail -> next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

Node* deleteNode(Node *head,int i){
	Node *temp = head;
	int count = 0;
	if(i == 0){									//deleting the first node.
		head = temp -> next;
		delete temp;
		return head;
	}
	while(temp != NULL && count < i - 1){		//deleting node at ith position and at the end.
		temp = temp -> next;
		count++;
	}
	if(temp == NULL || temp -> next == NULL){
		return head;
	}
	Node *a = temp -> next;
	temp -> next = a -> next;
	delete a;
	return head;
}

void print(Node *head){
	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head,pos);
		print(head);
	}
	return 0;
}
