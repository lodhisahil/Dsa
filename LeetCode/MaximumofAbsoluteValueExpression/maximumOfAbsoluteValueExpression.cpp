class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int ans = 0;
        for (int mask = 0; mask < 8; mask++) {
            int mx = INT_MIN;
            int mn = INT_MAX;
            for (int i = 0; i < n; i++) {
                int val = 0;
                if (mask & 1) {
                    val += arr1[i];
                } else {
                    val -= arr1[i];
                }
                if (mask & 2) {
                    val += arr2[i];
                } else {
                    val -= arr2[i];
                }
                if (mask & 4) {
                    val += i;
                } else {
                    val -= i;
                }
                mx = max(mx, val);
                mn = min(mn, val);
            }
            ans = max(ans, mx - mn);
        }
        return ans;
    }
};