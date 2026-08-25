class Solution {
public:
    void helper(int n, int open, int close, string currStr, vector<string>& ans){
        if(open == n && close == n){
            ans.push_back(currStr);
            return;
        }
        if(open < n){
            helper(n, open + 1, close, currStr + "(", ans);
        }
        if(close < open){
            helper(n, open, close + 1, currStr + ")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, 0, 0, "", ans);
        return ans;
    }
};