class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" ||
               tokens[i] == "-" ||
               tokens[i] == "*" ||
               tokens[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    int ans = b + a;
                    st.push(ans);
                }else if(tokens[i] == "-"){
                    int ans = b - a;
                    st.push(ans);
                }else if(tokens[i] == "*"){
                    int ans = b * a;
                    st.push(ans);
                }else{
                    int ans = b / a;
                    st.push(ans);
                }
               }else{
                st.push(stoi(tokens[i]));
               }
        }
        return st.top();
    }
};