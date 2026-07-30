class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        if(k == 0)return num;
        stack<char> st;
        for(char c : num){
            while(!st.empty() && st.top() > c && k > 0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k > 0){
            k--;
            st.pop();
        }
        if(st.empty()) return "0";
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(ans.size() != 0 && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() == 0) return "0";
        return ans;
    }
};