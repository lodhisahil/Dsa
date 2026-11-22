class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int x : nums) maxOr |= x;
        return dfs(nums, 0, 0, maxOr);
    }

private:
    int dfs(vector<int>& nums, int idx, int cur, int maxOr) {
        if (idx == nums.size()) return cur == maxOr ? 1 : 0;
        // nums[idx] ko lo + nums[idx] ko chhodo
        return dfs(nums, idx + 1, cur | nums[idx], maxOr) + dfs(nums, idx + 1, cur, maxOr);
    }
};