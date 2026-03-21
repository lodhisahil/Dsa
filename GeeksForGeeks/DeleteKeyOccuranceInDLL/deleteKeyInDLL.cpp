/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here
        Node* curr = *head_ref;
        while(curr != NULL){
            if(curr -> data == x){
                Node* next = curr->next;
                if(curr->prev == NULL){
                    *head_ref = curr->next;
                }else{
                    curr->prev->next = curr->next;
                }
                
                if(curr->next != NULL){
                    curr->next->prev = curr->prev;
                }
                delete curr;
                curr = next;
            }
            else{
                curr = curr->next;
            }
        }
        
    }
};