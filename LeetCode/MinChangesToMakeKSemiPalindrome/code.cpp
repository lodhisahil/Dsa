class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> divisors(n + 1);
        for (int d = 1; d <= n; d++)
            for (int len = 2 * d; len <= n; len += d)
                divisors[len].push_back(d);
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INF;
                for (int d : divisors[len]) {
                    int changes = 0;
                    for (int r = 0; r < d; r++) {
                        int lo = i + r;
                        int cnt = len / d;
                        int hi = lo + (cnt - 1) * d;
                        while (lo < hi) {
                            if (s[lo] != s[hi]) changes++;
                            lo += d;
                            hi -= d;
                        }
                    }
                    best = min(best, changes);
                }
                cost[i][j] = best;
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int m = 2 * (p - 1); m <= i - 2; m++) {
                    if (dp[p - 1][m] >= INF || cost[m][i - 1] >= INF) continue;
                    dp[p][i] = min(dp[p][i], dp[p - 1][m] + cost[m][i - 1]);
                }
            }
        }
        return dp[k][n];
    }
};