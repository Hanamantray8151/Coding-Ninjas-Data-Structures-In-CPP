//O(n) + O(n/2).
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* t = head;
        while(t != NULL){
            count++;
            t = t -> next;
        }
        int middleIndex;
        if(count % 2 == 0){
            middleIndex = count / 2;
        }else{
            middleIndex = count / 2;
        }
        
        int counter = 0;
        ListNode* temp = head;
        while(counter < middleIndex){
            counter++;
            temp = temp -> next;
        }
        return temp;
    }
};

//O(n/2).
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};
