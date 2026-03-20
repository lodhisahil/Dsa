/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* temp = head;
        Node* headZero = new Node(-1);
        Node* zero = headZero;
        Node* headOne = new Node(-1);
        Node* one = headOne;
        Node* headTwo = new Node(-1);
        Node* two = headTwo;
        while(temp != NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = zero->next;
            }else if(temp->data == 1){
                one->next = temp;
                one = one->next;
            }else {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        zero->next = (headOne->next) ? headOne->next : headTwo->next;
        one->next = headTwo->next;
        two->next = NULL;
        Node* newHead = headZero->next;
        delete headZero;
        delete headOne;
        delete headTwo;
        return newHead;
    }
};