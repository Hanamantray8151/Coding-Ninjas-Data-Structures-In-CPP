/*
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,'
then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'k'.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= k <= M

Time Limit:  1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4
Sample Output 2 :
1 2 3 4 5 
40 30 20 10 
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeinput(){
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
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

int length(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    return len;
}

Node* reverse(Node* head,Node* temp){
    Node* prev = NULL;
    Node* fwd = NULL;
    Node* curr = head;

    while(curr != temp){
        fwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

Node* kReverse(Node* head,int k){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    for(int i=0;i<k;i++){
        if(temp == NULL){
            return head;
        }
        temp = temp -> next;
    }
    Node* newHead = reverse(head,temp);
    Node* tempHead = kReverse(temp,k);
    head -> next = tempHead;
    return newHead;
}

Node* reverseLastRemainingNodes(Node* head,int k){
    int len = length(head);
    Node* temp = head;
    Node* prev = NULL;
    int count = 0;
    if(len % k != 0){
        int modValue = len % k;
        while(count < len - modValue){
            prev = temp;
            temp = temp -> next;
            count++;
        }
        Node* last = temp;
        while(last != NULL){
            last = last -> next;
        }
        Node* newHead = reverse(temp,last);
        prev -> next = newHead;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    Node* head = takeinput();
    int k;
    cin >> k;
    head = kReverse(head,k);
    Node* newhead = reverseLastRemainingNodes(head,k);
    print(newhead);

    return 0;
}
