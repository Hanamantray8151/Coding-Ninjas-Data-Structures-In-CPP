#include<bits/stdc++.h>
using namespace std;

class MaxPriorityQueue{
private:
    vector<int> pq;
public:
    bool isEmpty(){
        if(pq.size() == 0){
            return true;
        }
        return false;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(pq[parentIndex] < pq[childIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMax(){
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;
        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex;
            if(pq[minIndex] < pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[minIndex] < pq[rightChildIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = (2 * parentIndex) + 2;
        }
        return ans;
    }
};


int main(){
    MaxPriorityQueue pq;

    pq.insert(15);
    pq.insert(2);
    pq.insert(20);
    pq.insert(9);
    pq.insert(0);
    pq.insert(100);

    cout << pq.getSize() << endl;
    cout << pq.getMax() << endl;

    while(!pq.isEmpty()){
        cout << pq.removeMax() << " ";
    }
    cout << endl;

    return 0;
}
