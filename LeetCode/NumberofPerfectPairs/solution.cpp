class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            while (nums[right] > 2LL * nums[left]) {
                left++;
            }
            ans += right - left;
        }
        return ans;
    }
};