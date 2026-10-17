class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            vector<int> count(n + 1, 0);
            int distinct = 0;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                if (freq[x] == 0) {
                    distinct++;
                } else {
                    count[freq[x]]--;
                }
                freq[x]++;
                count[freq[x]]++;
                int len = j - i + 1;
                if (distinct == 1) {
                    ans = max(ans, len);
                    continue;
                }
                int mn = 1;
                while (mn <= len && count[mn] == 0) {
                    mn++;
                }
                if (mn * 2 <= len &&
                    count[mn] > 0 &&
                    count[2 * mn] > 0) {
                    int total = count[mn] + count[2 * mn];
                    if (total == distinct) {
                        ans = max(ans, len);
                    }
                }
            }
        }
        return ans;
    }
};