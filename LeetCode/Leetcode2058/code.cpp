/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        int pos = 1;
        int first = -1;
        int last = -1;
        int minimum = INT_MAX;
        while(curr->next != NULL){
            if((curr->val > prev->val && curr->val > curr->next->val) || 
               (curr->val < prev->val && curr->val < curr->next->val)){
                if(first == -1){
                    first = pos;
                }else{
                    minimum = min(minimum, pos - last);
                }
                last = pos;
            }
            curr = curr->next;
            prev = prev->next;
            pos++;
        }
        if(first == -1 || first == last){
            return {-1, -1};
        }
        int maximum = last - first;
        return {minimum, maximum};
    }
};