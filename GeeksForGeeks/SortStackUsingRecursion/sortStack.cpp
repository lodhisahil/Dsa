class Solution {
  public:
    void insert(stack<int> &st, int x){
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }
        int element = st.top();
        st.pop();
        insert(st, x);
        st.push(element);
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.size() == 0){
            return;
        }
        
        int x = st.top();
        st.pop();
        sortStack(st);
        insert(st, x);
    }
};