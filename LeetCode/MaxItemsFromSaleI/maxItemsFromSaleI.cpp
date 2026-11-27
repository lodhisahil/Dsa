class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> g(n, 0);
        int minP = INT_MAX;
        for (int i = 0; i < n; i++) {
            minP = min(minP, items[i][1]);
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) g[i]++;
            }
        }
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int w = items[i][1], v = 1 + g[i];
            for (int b = budget; b >= w; b--) {
                dp[b] = max(dp[b], dp[b - w] + v);
            }
        }
        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / minP);
        }
        return ans;
    }
};