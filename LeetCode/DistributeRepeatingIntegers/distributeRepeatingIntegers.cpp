class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        vector<int> cnt;
        for (auto& kv : freq) cnt.push_back(kv.second);
        int m = quantity.size();
        int full = (1 << m) - 1;
        vector<int> sum(1 << m, 0);
        for (int mask = 1; mask <= full; mask++) {
            int low = __builtin_ctz(mask);
            sum[mask] = sum[mask & (mask - 1)] + quantity[low];
        }
        vector<char> dp(1 << m, 0), ndp(1 << m, 0);
        dp[0] = 1;
        for (int c : cnt) {
            ndp = dp;
            for (int mask = 0; mask <= full; mask++) {
                if (!dp[mask]) continue;
                int rest = full ^ mask;
                for (int sub = rest; sub > 0; sub = (sub - 1) & rest) {
                    if (sum[sub] <= c) ndp[mask | sub] = 1;
                }
            }
            dp = ndp;
            if (dp[full]) return true;
        }
        return dp[full];
    }
};