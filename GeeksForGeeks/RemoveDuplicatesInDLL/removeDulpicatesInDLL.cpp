/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
*/
class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(head == NULL || head->next == NULL) return head;
        Node* temp1 = head;
        Node* temp2 = head->next;
        while(temp2 != NULL){
            if(temp1->data == temp2->data){
                //remove temp2 node
                Node* nextNode = temp2->next;
                temp1->next = nextNode;
                if(nextNode != NULL){
                    nextNode->prev = temp1;
                }
                
                delete temp2;
                temp2 = nextNode;
            }else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return head;
    }
};