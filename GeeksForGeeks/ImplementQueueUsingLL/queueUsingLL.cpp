class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

  public:
    Node* head;
    Node* tail;
    int count;
    myQueue() {
        // Initialize your data members
        head = NULL;
        tail = NULL;
        count = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return head == NULL;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* temp = new Node(x);
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(!isEmpty()){
            Node* temp = head;
            head = head->next;
            if(head == NULL){
                tail = NULL;
            }
            delete temp;
            count--;
        }
        
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }

    int size() {
        // Returns the current size of the queue.
        return count;
    }
};