/*
You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and 
deleted from both the ends.
You don't need to double the capacity.
You need to implement the following functions -
1. constructor
You need to create the appropriate constructor. Size for the queue passed is 10.
2. insertFront -
This function takes an element as input and insert the element at the front of queue. Insert the element only if 
queue is not full. And if queue is full, print -1 and return.
3. insertRear -
This function takes an element as input and insert the element at the end of queue. Insert the element only if 
queue is not full. And if queue is full, print -1 and return.
4. deleteFront -
This function removes an element from the front of queue. Print -1 if queue is empty.
5. deleteRear -
This function removes an element from the end of queue. Print -1 if queue is empty.
6. getFront -
Returns the element which is at front of the queue. Return -1 if queue is empty.
7. getRear -
Returns the element which is at end of the queue. Return -1 if queue is empty.
Input Format:
For C++ and Java, input is already managed for you. You just have to implement given functions.

Output Format:
For C++ and Java, output is already managed for you. You just have to implement given functions.

For Python: 
The output format for each function has been mentioned in the problem description itself. 
Sample Input 1:
5
1
49
1
64
2
99
5
6
-1
Sample Output 1:
-1
64
99
Explanation:
The first choice code corresponds to getFront. Since the queue is empty, hence the output is -1. 
The following input adds 49 at the top and the resultant queue becomes: 49.
The following input adds 64 at the top and the resultant queue becomes: 64 -> 49
The following input add 99 at the end and the resultant queue becomes: 64 -> 49 -> 99
The following input corresponds to getFront. Hence the output is 64.
The following input corresponds to getRear. Hence the output is 99.
*/

#include<bits/stdc++.h>
using namespace std;

class Deque { 
    int arr[10];
    int front;
    int rear;
    int size;
    public :
        Deque(int size) {
            front = -1;
            rear = 0;
            this -> size = size;
        }
    //Checks whether deque is full or not.
    bool isFull() {
        // used % operator is insertion and deletion is in circular manner 
        return (front == (rear + 1) % size);
    }
    //Checks whether Deque is empty or not.
    bool isEmpty () {
        return (front == -1);
    }
    // Inserts an element at front 
    void insertFront(int input) {
        if (isFull()) {
            cout << "-1\n";
            return;
        }
        if (isEmpty()) {    //isEmpty() ?
            front = 0;
            rear = 0;
        }
        else {
            // used % operator is insertion is in circular manner
            front = ((front - 1) % size + size) % size;
        }
        arr[front] = input ;
    } 
    // function to inset element at rear end of Deque. 
    void insertRear(int input) {
        if (isFull()) { 
            cout << "-1\n ";
            return;
        }
        if (isEmpty()) { 
            front = 0;
            rear = 0;
        }
        else {
            // used % operator is insertion is in circular manner
            rear = (rear + 1) % size;
        }
        arr[rear] = input;
    }
    // Deletes element at front end of Deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "-1\n";
            return ;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            // used % operator is deletion is in circular manner
            front = (front + 1) % size;
        }
    }
    // Delete element at rear end of Deque
    void deleteRear() { 
        if (isEmpty()) {
            cout << "-1\n";
            return ;
        }
        if (front == rear) { 
            front = -1;
            rear = -1; 
        }
        else {
            // used % operator is deletion is in circular manner
            rear = ((rear-1) % size + size) % size;
        }
    }
    // Returns front element of Deque 
    int getFront() {
        if (isEmpty()) { 
            return -1 ;
        }
        return arr[front];
    }
    // function return rear element of Deque 
    int getRear() {
        if(isEmpty()) {
            return -1 ;
        }
        return arr[rear];
    }
};

int main(){
    Deque dq(10);
    int choice,input;
    while(true){
        cin >> choice;
        switch(choice){
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    return 0;
}
