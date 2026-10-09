class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;
        for (char ch : s) {
            if (ch == '(') {
                if (open > 0 && open % 2 == 1) {
                    ans++;
                    open--;
                }
                open += 2;
            } 
            else {
                open--;
                if (open < 0) {
                    ans++;
                    open = 1;
                }
            }
        }
        return ans + open;
    }
};