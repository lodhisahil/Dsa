class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int diff = nums[i] - nums[0];
            if (diff == 0 || diff % 2 != 0) {
                continue;
            }
            int k = diff / 2;
            unordered_map<int, int> freq;
            for (int x : nums) {
                freq[x]++;
            }
            vector<int> ans;
            bool valid = true;
            for (int x : nums) {
                if (freq[x] == 0) {
                    continue;
                }
                int low = x;
                int high = x + 2 * k;
                if (freq[low] == 0 || freq[high] == 0) {
                    valid = false;
                    break;
                }
                freq[low]--;
                freq[high]--;
                ans.push_back(x + k);
            }
            if (valid && ans.size() == n / 2) {
                return ans;
            }
        }
        return {};
    }
};