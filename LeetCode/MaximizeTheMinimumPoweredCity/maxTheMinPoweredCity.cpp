class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> pre(n + 1, 0), power(n);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + stations[i];
        for (int i = 0; i < n; i++) {
            int lo = max(0, i - r), hi = min(n - 1, i + r);
            power[i] = pre[hi + 1] - pre[lo];
        }
        auto can = [&](long long target) {
            vector<long long> add(n + 1, 0);
            long long running = 0, remaining = k;
            for (int i = 0; i < n; i++) {
                running += add[i];
                long long cur = power[i] + running;
                if (cur < target) {
                    long long need = target - cur;
                    remaining -= need;
                    if (remaining < 0) return false;
                    running += need;
                    if (i + 2LL * r + 1 < n) add[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };
        long long lo = *min_element(power.begin(), power.end());
        long long hi = lo + k;
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            if (can(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};