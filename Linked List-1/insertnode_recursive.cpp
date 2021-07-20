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

Node* insertNode(Node *head,int i,int data){
	if(head == NULL){
		return head;
	}
	Node *newNode;
	if(i == 0){
		newNode = new Node(data);
		newNode -> next = head;
		head = newNode;
		return head;
	}
	Node *temp = head;
	Node *x = insertNode(head -> next,i - 1,data);
	temp -> next = x;
	temp = x;
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
		int data;
		cin >> data;
		head = insertNode(head,pos,data);
		print(head);
	}
	
	return 0;
}
