#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(42);
    pq.push(23);
    pq.push(12);
    pq.push(55);
    pq.push(6);
    pq.push(18);

    cout << pq.size() << endl;
    cout << pq.top() << endl;

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}
