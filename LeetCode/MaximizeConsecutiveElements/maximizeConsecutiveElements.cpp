class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 1;
        for (int x : nums) {
            // Raise to x+1 first (uses old dp[x])
            dp[x + 1] = dp[x] + 1;
            // Then keep as x (uses dp[x-1])
            dp[x] = dp[x - 1] + 1;
            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};