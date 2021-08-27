//O(max(n1,n2)). Here n1 and n2 are length of the two linked lists.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry){
            int sum = 0;
            if(l1 != NULL){
                sum = sum + (l1 -> val);
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum = sum + (l2 -> val);
                l2 = l2 -> next;
            }
            sum = sum + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            temp -> next = newNode;
            temp = newNode;
        }
        return dummy -> next;
    }
};
