/*
Given a linked list You need to reverse it iteratively and return head of the reversed linked list.
*/

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

Node* reverseLinkedList(Node *head){
	Node *current = head;
	Node *forward = NULL;
	Node *previous = NULL;
	
	while(current != NULL){
		forward = current -> next;
		current -> next = previous;
		previous = current;
		current = forward;
	}
	return previous;
}

void print(Node *head){
	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
	cout << "NULL" << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		Node *head = takeinput();
		head = reverseLinkedList(head);
		print(head);
	}
	
	return 0;
}
