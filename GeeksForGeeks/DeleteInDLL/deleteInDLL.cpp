/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        Node* temp = head;
        while(x > 1){
            temp = temp->next;
            x--;
        }
        //head is deleting
        if(temp->prev == NULL){
            head = temp->next;
            if(head != NULL){
                head->prev = NULL;
            }
        }else{
            temp->prev->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
        }
        delete temp;
        return head;
    }
};