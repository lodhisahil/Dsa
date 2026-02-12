class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(count < k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            count++;
        }
        ListNode* prevNode = reverseKGroup(temp, k);

        temp = head;
        count = 0;
        while(count < k){
        ListNode* next = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = next;
        count++;  
        }

        return prevNode;
    }
};