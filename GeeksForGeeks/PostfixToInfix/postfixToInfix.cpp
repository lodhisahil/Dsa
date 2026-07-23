class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        stack<string> st;
        for(int i=0; i<exp.length(); i++){
            if((exp[i] >= 'A' && exp[i] <= 'Z') ||
               (exp[i] >= 'a' && exp[i] <= 'z') ||
               (exp[i] >= '0' && exp[i] <= '9')){
                   st.push(string(1, exp[i]));
               }else{
                   string t1 = st.top();
                   st.pop();
                   string t2 = st.top();
                   st.pop();
                   string cur = '(' + t2 + exp[i] + t1 + ')';
                   st.push(cur);
               }
        }
        return st.top();
    }
};