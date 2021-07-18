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

void print(Node *head){
	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main(){
	//Creating the nodes statically.
	Node n1(1);
	Node *head1 = &n1;
	
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	cout << "Statically Created Nodes : ";
	print(head1);
	
  //Creating the nodes dynamically.
	Node *n6 = new Node(10);
	Node *head2 = n6;
	
	Node *n7 = new Node(20);
	Node *n8 = new Node(30);
	Node *n9 = new Node(40);
	Node *n10 = new Node(50);
	
	n6 -> next = n7;
	n7 -> next = n8;
	n8 -> next = n9;
	n9 -> next = n10;
	cout << "Dynamically Created Nodes : ";
	print(head2);
	
	return 0;
}
