class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int open = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
                ans += c;
            }
            else if (c == ')') {
                if (open == 0) {
                    continue;
                }
                open--;
                ans += c;
            }
            else {
                ans += c;
            }
        }
        string result = "";
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] == '(' && open > 0) {
                open--;
                continue;
            }
            result += ans[i];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};