class Solution {
  public:
  
    int priority(char a){
        if(a == '^')return 3;
        if(a == '*' || a == '/')return 2;
        return 1;
    }
  
    string infixToPostfix(string& s) {
        // code here
        int i = 0;
        stack<char> st;
        string ans = "";
        while(i < s.size()){
            if((s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= '0' && s[i] <= '9')){
                   ans += s[i];
               }else if(s[i] == '('){
                   st.push(s[i]);
               }else if(s[i] == ')'){
                   while(!st.empty() && st.top() != '('){
                       ans += st.top();
                       st.pop();
                   }
                   st.pop();
               }
               else{
                   while(!st.empty() && st.top() != '(' && ((priority(s[i]) < priority(st.top())) ||
                     (priority(s[i]) == priority(st.top()) && s[i] != '^'))){
                       ans += st.top();
                       st.pop();
                   }
                   st.push(s[i]);
               }
               i++;
               
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};