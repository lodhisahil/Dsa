class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<bitset<1024>> dp(n);
        dp[0][grid[0][0]] = 1;
        for (int j = 1; j < n; j++) {
            for (int x = 0; x < 1024; x++) {
                if (dp[j - 1][x]) {
                    dp[j][x ^ grid[0][j]] = 1;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<1024> curr;
                if (j > 0) {
                    curr |= dp[j - 1];
                }
                curr |= dp[j];
                bitset<1024> next;
                for (int x = 0; x < 1024; x++) {
                    if (curr[x]) {
                        next[x ^ grid[i][j]] = 1;
                    }
                }
                dp[j] = next;
            }
        }
        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }
        return 0;
    }
};