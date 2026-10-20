class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool ok = true;
            int prevMax = 0;
            for (int start = 0; start < n && ok; start += k) {
                int desc = 0;
                int mn = nums[start], mx = nums[start];
                for (int i = 0; i < k; i++) {
                    int cur = nums[start + i];
                    int nxt = nums[start + (i + 1) % k];
                    if (cur > nxt) {
                        if (++desc > 1) break;
                    }
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }
                if (desc > 1 || mn < prevMax) {
                    ok = false;
                    break;
                }
                prevMax = mx;
            }
            if (ok) total += k;
        }
        return (int)total;
    }
};