class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int l = 0;
        int r = 0;
        int n = popped.size();
        while(l < n){
            st.push(pushed[l]);
            l++;
            while(!st.empty() && st.top() == popped[r] && r < n){
                st.pop();
                r++;
            }
        }
        return r == n;
    }
};