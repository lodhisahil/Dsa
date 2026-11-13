class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> primes;
        vector<bool> isP(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (isP[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= n; j += i) isP[j] = false;
            }
        }
        int m = primes.size();
        if (m == 0 || primes[0] > s) return {};
        const int INF = 1e9;
        vector<vector<int>> dp(m + 1, vector<int>(s + 1, INF));
        dp[m][0] = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j <= s; j++) {
                dp[i][j] = dp[i + 1][j];
                if (j >= primes[i] && dp[i + 1][j - primes[i]] != INF)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - primes[i]] + 1);
            }
        }
        int best = -1;
        for (int j = s; j >= 1; j--) {
            if (dp[0][j] != INF) { best = j; break; }
        }
        if (best == -1) return {};
        vector<int> ans;
        int j = best;
        for (int i = 0; i < m && j > 0; i++) {
            if (j >= primes[i] &&
                dp[i + 1][j - primes[i]] != INF &&
                dp[i + 1][j - primes[i]] + 1 == dp[i][j]) {
                ans.push_back(primes[i]);
                j -= primes[i];
            }
        }
        return ans;
    }
};