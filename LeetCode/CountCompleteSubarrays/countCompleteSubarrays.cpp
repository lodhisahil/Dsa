class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int totalDistinct = st.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> curr;
            for (int j = i; j < n; j++) {
                curr.insert(nums[j]);
                if (curr.size() == totalDistinct) {
                    ans += n - j;
                    break;
                }
            }
        }
        return ans;
    }
};