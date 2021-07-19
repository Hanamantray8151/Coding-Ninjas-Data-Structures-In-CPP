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
	int count = 0;
	Node *temp = head;
	Node *newNode = new Node(data);
	if(i == 0){								//Inserting at the beginning.
		newNode -> next = head;
		head = newNode;
		return head;
	}
	while(temp != NULL && count < i - 1){	//Inserting at ith position and at the end.
		temp = temp -> next;
		count++;
	}
	if(temp != NULL){						//if temp != NULL then only these statements will execute.
	newNode -> next = temp -> next;
	temp -> next = newNode;
	}
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
		int element;
		cin >> element;
		head = insertNode(head,pos,element);
		print(head);
	}
	return 0;
}
