#include<bits/stc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

int length(Node *head){
    int len = 0;
    Node *temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

Node *appendLastNToFirst(Node *head, int n)
{
    int len = length(head);
    int count = 0;
    Node *temp = head;
    if(head == NULL){
        return head;
    }
    if(n == 0){
        return head;
    }
    while(count < len - n - 1){
        count++;
        temp = temp -> next;
    }
    Node *first = head;
    Node *middle = temp -> next;
   	head = temp -> next;
    temp -> next = NULL;
    while(middle -> next != NULL){
        middle = middle -> next;
    }
    middle -> next = first;
    return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
