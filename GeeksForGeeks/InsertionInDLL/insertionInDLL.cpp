/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* temp = head;
        while(p > 0){
            temp = temp->next;
            p--;
        }
        Node* node = new Node(x);
        node->next = temp->next;
        temp->next = node;
        node->prev = temp;
        if(node->next != NULL){
            node->next->prev = node;
        }
        return head;
    }
};