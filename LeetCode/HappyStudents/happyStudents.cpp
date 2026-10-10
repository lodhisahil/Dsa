class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        if (nums[0] > 0) {
            ans++;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < i && nums[i] > i) {
                ans++;
            }
        }
        if (nums[n - 1] < n) {
            ans++;
        }
        return ans;
    }
};