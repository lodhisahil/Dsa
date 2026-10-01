class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int pos, int mask) {
        if (pos > n) {
            return 1;
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }
        int ans = 0;
        for (int num = 1; num <= n; num++) {
            if (mask & (1 << (num - 1))) {
                continue;
            }
            if (num % pos == 0 || pos % num == 0) {
                int newMask = mask | (1 << (num - 1));
                ans += solve(pos + 1, newMask);
            }
        }
        return dp[mask] = ans;
    }
    int countArrangement(int n) {
        this->n = n;
        dp.resize(1 << n, -1);
        return solve(1, 0);
    }
};