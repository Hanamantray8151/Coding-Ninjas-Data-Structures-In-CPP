/*
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
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

Node* evenAfterOdd(Node *head){
	Node *oddHead = NULL;
	Node *oddTail = NULL;
	Node *evenHead = NULL;
	Node *evenTail = NULL;
	
	while(head != NULL){
		if(head -> data % 2 != 0){	//Condition for odd.
			if(oddHead == NULL){
				oddHead = head;
				oddTail = head;
			}else{
				oddTail -> next = head;
				oddTail = head;
			}
			head = head -> next;
		}else{						//Condition for even.
			if(evenHead == NULL){
				evenHead = head;
				evenTail = head;
			}else{
				evenTail -> next = head;
				evenTail = head;
			}
			head = head -> next;
		}
	}
	if(oddHead == NULL && oddTail == NULL){		//For the testcase 2 4 6,here both oddHead and oddTail are NULL.
		return evenHead;
	}
	if(evenHead == NULL && evenTail == NULL){	//For the testcase 1 3 5,here both evenHead and evenTail are NULL.
		return oddHead;
	}
	//For the mixed testcase 1 2 3 4 5 8,we need to place null in oddTail->next and evenTail->next 
  	//to ensure that two linked lists are splitted.
	oddTail -> next = NULL;
	evenTail -> next = NULL;
	oddTail -> next = evenHead;
	return oddHead;
}

void print(Node *head){
	Node *temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	
	while(t--){
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}

	return 0;
}
