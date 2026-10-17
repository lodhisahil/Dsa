class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> ans;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int coin = 1; coin <= n; coin++) {
            if (dp[coin] == numWays[coin - 1]) {
                continue;
            }
            if (dp[coin] + 1 != numWays[coin - 1]) {
                return {};
            }
            ans.push_back(coin);
            for (int amount = coin; amount <= n; amount++) {
                dp[amount] += dp[amount - coin];
            }
        }
        return ans;
    }
};