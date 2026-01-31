class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* left1 = head;
        stack<int> s;
        for(int i=1; i<left; i++){
            left1 = left1->next;
        }
        for(int i=0; i<right-left+1; i++){
            s.push(left1->val);
            left1 = left1->next;
        }
        left1 = head;
        for(int i=1; i<left; i++){
            left1 = left1->next;
        }
        for(int i=0; i<right-left+1; i++){
            left1->val = s.top();
            s.pop();
            left1 = left1->next;
        }
    return head;
    }
};