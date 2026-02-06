class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int sz = 0;
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }
        if(sz == n){
            ListNode *del = head;
            head = head->next;
            del->next = NULL;
            return head;
        }
        temp = head;
        for(int i=0; i<sz-n-1; i++){
            temp = temp->next;
        }
        ListNode *nxt = temp->next;
        temp->next = nxt->next;
        nxt->next = NULL;
        return head;
    }
};