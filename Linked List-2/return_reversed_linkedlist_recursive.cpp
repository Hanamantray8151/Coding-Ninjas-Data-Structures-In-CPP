/*
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. You have to do this in O(N) time complexity where N is the size of the linked list.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1
Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10 
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

class Pair{
	public:
		Node *head;
		Node *tail;
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

Node* reverseLL_3(Node *head){				//O(n).	//Method-1.
	if(head == NULL || head -> next == NULL){
		return head;
	}
	
	Node *smallans = reverseLL_3(head -> next);
	
	Node *tail = head -> next;
	tail -> next = head;
	head -> next = NULL;
	return smallans;
}

Pair reverseLL_2(Node *head){				//O(n). //Method-2.
	if(head == NULL || head -> next == NULL){
		Pair ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}
	
	Pair smallans = reverseLL_2(head -> next);
	smallans.tail -> next = head;
	head -> next = NULL;
	
	Pair ans;
	ans.head = smallans.head;
	ans.tail = head;
	return ans;
}

Node* reverseLL_better(Node *head){
	return reverseLL_2(head).head;
}

Node* reverseLinkedListRec(Node *head){			//O(n^2). //Method-3.
	if(head == NULL || head -> next == NULL){
		return head;
	}
	
	Node *smallans = reverseLinkedListRec(head -> next);
	Node *temp = smallans;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> next = head;
	head -> next = NULL;
	return smallans;
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
		//head = reverseLinkedListRec(head);	//O(n^2).
		//head = reverseLL_better(head);	//O(n).
		head = reverseLL_3(head);		//O(n).
		print(head);
	}

	return 0;
}
