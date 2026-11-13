class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        long long ans = 0, cost = 0;
        deque<int> dq;
        int r = 0;
        int l = 0;
        for (r = 0; r < n; r++) {
            while (!dq.empty() && nums[dq.back()] <= nums[r]) {
                int j = dq.back();
                dq.pop_back();
                int left = dq.empty() ? l : dq.back() + 1;
                cost += (long long)(nums[r] - nums[j]) * (j - left + 1);
            }
            dq.push_back(r);
            while (cost > k) {
                if (dq.front() == l) {
                    dq.pop_front();
                } else {
                    cost -= (long long)(nums[dq.front()] - nums[l]);
                }
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};