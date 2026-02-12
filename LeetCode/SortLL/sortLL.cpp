class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<int> arr;
        ListNode* curr = head;
        while(curr){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        sort(arr.begin(), arr.end());
        ListNode* head1 = new ListNode(arr[0]);
        ListNode* prev = head1;
        for(int i=1; i<arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]); 
            prev->next = temp;
            prev = temp;
        }
        return head1;
    }
};