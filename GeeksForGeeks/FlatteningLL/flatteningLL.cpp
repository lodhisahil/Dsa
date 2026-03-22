/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* merge2LL(Node* list1, Node* list2){
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;
        while(list1 != NULL && list2 != NULL){
            if(list1->data < list2->data){
                curr->bottom = list1;
                curr = list1;
                list1 = list1->bottom;
            }else {
                curr->bottom = list2;
                curr = list2;
                list2 = list2->bottom;
            }
            curr->next = NULL;
        }
        if(list1){
            curr->bottom = list1;
        }
        if(list2){
            curr->bottom = list2;
        }
        Node* head = dummyNode->bottom;
        delete dummyNode;
        return head;
    }
  
    Node *flatten(Node *root) {
        // code here
        if(root == NULL || root->next == NULL){
            return root;
        }
        Node* mergedHead = flatten(root->next);
        root = merge2LL(root, mergedHead);
        return root;
    }
};