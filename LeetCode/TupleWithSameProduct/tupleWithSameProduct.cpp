class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        freq.reserve(n * n / 2 + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prod = nums[i] * nums[j];
                ans += 8 * freq[prod];
                freq[prod]++;
            }
        }
        return ans;
    }
};