class Solution {
    static const long long MOD = 1e9 + 7;
    vector<long long> sum, sq, lazy;
    void apply(int node, int len, long long v) {
        sq[node] = (sq[node] + 2 * v % MOD * sum[node] + v * v % MOD * len) % MOD;
        sum[node] = (sum[node] + v * len) % MOD;
        lazy[node] += v;
    }
    void push(int node, int l, int r) {
        if (lazy[node]) {
            int mid = (l + r) / 2;
            apply(2 * node, mid - l + 1, lazy[node]);
            apply(2 * node + 1, r - mid, lazy[node]);
            lazy[node] = 0;
        }
    }
    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, 1);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);
        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        sq[node] = (sq[2 * node] + sq[2 * node + 1]) % MOD;
    }
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        vector<int> last(100001, -1);
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int p = last[nums[j]];
            update(1, 0, n - 1, p + 1, j);
            last[nums[j]] = j;
            ans = (ans + sq[1]) % MOD;
        }
        return (int)ans;
    }
};