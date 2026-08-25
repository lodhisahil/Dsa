class Solution {
  public:
    void insertAtBottom(stack<int>& st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int topElement = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(topElement);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int x = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, x);
    }
};