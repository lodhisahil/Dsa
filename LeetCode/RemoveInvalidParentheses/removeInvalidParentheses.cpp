class Solution {
public:
    unordered_set<string> st;
    void solve(string &s, int index, int leftRemove, int rightRemove, int balance, string current) {
        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0) {
                st.insert(current);
            }
            return;
        }
        char ch = s[index];
        if (ch != '(' && ch != ')') {
            solve(s, index + 1, leftRemove, rightRemove, balance, current + ch);
            return;
        }
        if (ch == '(' && leftRemove > 0) {
            solve(s, index + 1, leftRemove - 1, rightRemove, balance, current);
        }
        if (ch == ')' && rightRemove > 0) {
            solve(s, index + 1, leftRemove, rightRemove - 1, balance, current);
        }
        if (ch == '(') {
            solve(s, index + 1, leftRemove, rightRemove, balance + 1, current + ch);
        }
        else {
            if (balance > 0) {
                solve(s, index + 1, leftRemove, rightRemove, balance - 1, current + ch);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;
        for (char ch : s) {
            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {
                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }
        solve(s, 0, leftRemove, rightRemove, 0, "");
        return vector<string>(st.begin(), st.end());
    }
};