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
	if(head == NULL){
		return head;
	}
	if(i == 0){
		Node *temp = head;
		head = head -> next;
		delete temp;
		return head;
	}
	Node *x = deleteNode(head -> next,i - 1);
	head -> next = x;
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
