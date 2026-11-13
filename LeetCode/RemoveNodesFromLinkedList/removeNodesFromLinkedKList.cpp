class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr) return nullptr;
        head = reverse(head);
        int maxNode = head->val;
        ListNode* temp = head;
        while(temp->next) {
            if(temp->next->val < maxNode) {
                ListNode* del = temp->next;
                temp->next = del->next;
            }
            else {
                temp = temp->next;
                maxNode = temp->val;
            }
        }
        return reverse(head);
    }
};