
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* curr = head;
        while(curr != NULL){
            s.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL){
            if(s.top() != curr->val){
                return false;
            }
            s.pop();
            curr = curr->next;
        }
        return true;
    }
};