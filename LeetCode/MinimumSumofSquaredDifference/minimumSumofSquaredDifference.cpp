class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> diff;
        int mx = 0;
        long long total = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            mx = max(mx, d);
            total += d;
        }
        if (k >= total) {
            return 0;
        }
        int low = 0, high = mx;
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long ops = 0;
            for (int d : diff) {
                if (d > mid) {
                    ops += d - mid;
                }
            }
            if (ops <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        int limit = low;
        long long ans = 0;
        for (int d : diff) {
            int reduced = min(d, limit);
            ans += 1LL * reduced * reduced;
            k -= d - reduced;
        }
        for (int i = 0; i < diff.size() && k > 0; i++) {
            if (diff[i] >= limit && limit > 0) {
                ans -= 1LL * limit * limit;
                ans += 1LL * (limit - 1) * (limit - 1);
                k--;
            }
        }
        return ans;
    }
};