class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool forward = true, backward = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                forward = false;
            }
            if (nums[(pos - i + n) % n] != i) {
                backward = false;
            }
        }
        int ans = INT_MAX;
        if (forward) {
            ans = min(pos, n - pos + 2);
        }
        if (backward) {
            int rotations = n - 1 - pos;
            ans = min(ans, 1 + min(rotations, n - rotations));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};