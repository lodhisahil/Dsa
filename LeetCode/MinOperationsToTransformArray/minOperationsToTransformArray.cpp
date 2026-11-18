class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int target = nums2[n];
        long long total = 0;
        long long extra = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            int a = nums1[i], b = nums2[i];
            total += abs(a - b);
            int lo = min(a, b), hi = max(a, b);
            long long d;
            if (target >= lo && target <= hi) d = 0;
            else d = min(abs(target - lo), abs(target - hi));
            extra = min(extra, d);
        }
        return total + 1 + extra;
    }
};