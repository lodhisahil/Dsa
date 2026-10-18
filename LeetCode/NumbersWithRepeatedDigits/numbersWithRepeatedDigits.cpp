class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int len = s.size();
        int unique = 0;
        for (int l = 1; l < len; l++) {
            int ways = 9;
            for (int j = 1; j < l; j++) {
                ways *= (10 - j);
            }
            unique += ways;
        }
        vector<bool> used(10, false);
        for (int i = 0; i < len; i++) {
            int curr = s[i] - '0';
            int start = (i == 0) ? 1 : 0;
            for (int d = start; d < curr; d++) {
                if (used[d]) {
                    continue;
                }
                int ways = 1;
                int remaining = len - i - 1;
                for (int j = 0; j < remaining; j++) {
                    ways *= (9 - i - j);
                }
                unique += ways;
            }
            if (used[curr]) {
                break;
            }
            used[curr] = true;
            if (i == len - 1) {
                unique++;
            }
        }
        return n - unique;
    }
};