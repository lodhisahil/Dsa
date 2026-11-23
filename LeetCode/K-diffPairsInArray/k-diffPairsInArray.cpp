class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int count = 0;
        for (auto& [x, f] : freq) {
            if (k == 0) {
                if (f >= 2) count++;
            } else {
                if (freq.count(x + k)) count++;
            }
        }
        return count;
    }
};