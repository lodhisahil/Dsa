class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int total = 0;
        for (int r : rods) total += r;
        vector<int> dp(total + 1, -1);
        dp[0] = 0;
        for (int r : rods) {
            vector<int> next = dp;
            for (int d = 0; d <= total; d++) {
                if (dp[d] < 0) continue;
                int h = dp[d];
                // add to the taller support
                if (d + r <= total)
                    next[d + r] = max(next[d + r], h + r);
                // add to the shorter support
                if (r <= d) {
                    next[d - r] = max(next[d - r], h);
                } else {
                    next[r - d] = max(next[r - d], h - d + r);
                }
            }
            dp = move(next);
        }
        return dp[0];
    }
};