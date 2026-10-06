class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        // Remove duplicates
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        map<int, int> dp;
        dp[-1] = 0;
        for (int x : arr1) {
            map<int, int> next;
            for (auto [prev, ops] : dp) {
                // Option 1: Keep arr1[i]
                if (x > prev) {
                    if (!next.count(x) || next[x] > ops) {
                        next[x] = ops;
                    }
                }
                // Option 2: Replace arr1[i]
                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end()) {
                    int y = *it;
                    if (!next.count(y) || next[y] > ops + 1) {
                        next[y] = ops + 1;
                    }
                }
            }
            dp = next;
            if (dp.empty()) {
                return -1;
            }
        }
        int ans = INT_MAX;
        for (auto [prev, ops] : dp) {
            ans = min(ans, ops);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};