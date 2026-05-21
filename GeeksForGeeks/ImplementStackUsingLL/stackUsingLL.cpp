/* Structure of linked list Node
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
class myStack {

  public:
    Node* head;
    int sz;
    myStack() {
        // Initialize your data members
        head = NULL;
        sz = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return head == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* node = new Node(x);
        node->next = head;
        head = node;
        sz++;
    }

    void pop() {
        // Removes the top element of the stack
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        sz--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(head == NULL){
            return -1;
        }
        return head->data;
    }

    int size() {
        // Returns the current size of the stack.
        return sz;
    }
};