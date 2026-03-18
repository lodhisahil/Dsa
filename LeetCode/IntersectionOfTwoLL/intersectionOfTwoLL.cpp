/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* collision(ListNode *temp1, ListNode *temp2, int n){
        while(n != 0){
            temp2 = temp2->next;
            n--;
        }
        while(temp1 != temp2 && temp1 != NULL){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int n1 = 0;
        int n2 = 0;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        while(temp1){
            n1++;
            temp1 = temp1->next;
        }
        while(temp2){
            n2++;
            temp2 = temp2->next;
        }

        if(n1 < n2){
            return collision(head1, head2, n2-n1);
        }else{
            return collision(head2, head1, n1-n2);
        }
        return NULL;
    }
};