class myStack {
    int size;
    int *stack;
    int top;
  public:
    myStack(int n) {
        size = n;
        stack = new int[size];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top+1 == size;
    }

    void push(int x) {
        if(top+1 < size){
            top = top+1;
            stack[top] = x;
        }
    }

    void pop() {
        if(top>=0){
            top--;
        }
    }

    int peek() {
        if(top>=0){
            return stack[top];
        }else{
            return -1;
        }
    }
};