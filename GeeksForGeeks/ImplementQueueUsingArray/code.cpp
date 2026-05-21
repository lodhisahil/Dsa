class myQueue {

  public:
    int start;
    int end;
    int *queue;
    int size;
    
    myQueue(int n) {
        // Define Data Structures
        size = n;
        start = -1;
        end = -1;
        queue = new int[size];
    }

    bool isEmpty() {
        // check if the queue is empty
        return (start == -1);
    }

    bool isFull() {
        // check if the queue is full
        return ((end + 1) % size == start);
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()){
            return;
        }
        if(start == -1){
            start = 0;
            end = 0;
        }else{
            end = (end + 1) % size;
        }
        queue[end] = x;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()){
            return;
        }
        if(start == end){
            start = -1;
            end = -1;
        }else{
            start = (start + 1) % size;
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()){
            return-1;
        }
        return queue[start];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()){
            return -1;
        }
        return queue[end];
    }
};