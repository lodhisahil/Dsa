class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> mp;
        long long prefix = 0;
        long long ans = LLONG_MIN;
        for (int x : nums) {
            prefix += x;
            if (mp.count((long long)x - k)) {
                ans = max(ans, prefix - mp[(long long)x - k]);
            }
            if (mp.count((long long)x + k)) {
                ans = max(ans, prefix - mp[(long long)x + k]);
            }
            if (!mp.count(x)) {
                mp[x] = prefix - x;
            } else {
                mp[x] = min(mp[x], prefix - x);
            }
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};