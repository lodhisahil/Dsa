class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        // dp[j][k]: schemes using exactly j members with capped profit k
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < (int)group.size(); i++) {
            int g = group[i], p = profit[i];
            for (int j = n; j >= g; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    int nk = min(minProfit, k + p);
                    dp[j][nk] = (dp[j][nk] + dp[j - g][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; j++) {
            ans = (ans + dp[j][minProfit]) % MOD;
        }
        return ans;
    }
};