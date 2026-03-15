/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        if(head->next == NULL){
            return head->data == key ? true : false;
        }
        Node* node = head;
        while(node != NULL){
            if(node->data == key){
                return true;
            }
            node = node->next;
        }
        return false;
    }
};
