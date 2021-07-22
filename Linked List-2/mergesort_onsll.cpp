/*
Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
3 4 5 6 7 8 9 10 
Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
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
	Node *head = NULL, *tail = NULL;
	while (data != -1){
		Node *newnode = new Node(data);
		if (head == NULL){
			head = newnode;
			tail = newnode;
		}else{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

Node* midPoint(Node *head){
	Node *slow = head;
	Node *fast = head -> next;
	
	while(fast != NULL && fast -> next != NULL){
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	return slow;
}

Node* mergeTwoSortedLists(Node *h1,Node *h2){
	Node *fh = NULL;
	Node *ft = NULL;
	
	while(h1 != NULL && h2 != NULL){
		if(h1 -> data <= h2 -> data){
			if(fh == NULL){
				fh = h1;
				ft = h1;
			}else{
				ft -> next = h1;
				ft = h1;
			}
			h1 = h1 -> next;
		}else{
			if(fh == NULL){
				fh = h2;
				ft = h2;
			}else{
				ft -> next = h2;
				ft = h2;
			}
			h2 = h2 -> next;
		}
	}
	if(h1 != NULL){
		ft -> next = h1;
	}
	if(h2 != NULL){
		ft -> next = h2;
	}
	return fh;
}

Node* mergeSort(Node *head){
	if(head == NULL || head -> next == NULL){
		return head;
	}
	//Splitting into two linked lists.
	Node *mid = midPoint(head);
	Node *firstHead = head;
	Node *secondHead = mid -> next;
	mid -> next = NULL;
	//Calling recursion on two halves.
	Node *head1 = mergeSort(firstHead);
	Node *head2 = mergeSort(secondHead);
	//Merging two lists.
	Node *finalHead = mergeTwoSortedLists(head1,head2);
	return finalHead;
}

void print(Node *head){
	Node *temp = head;
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
