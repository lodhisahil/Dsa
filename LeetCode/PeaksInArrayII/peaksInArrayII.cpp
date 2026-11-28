class Solution {
    struct Node {
        bool has = false;
        int f = 0, l = 0;
        long long B = 0;
    };
    int n;
    vector<int> a;
    vector<Node> t;
    Node merge(const Node &x, const Node &y) {
        if (!x.has) return y;
        if (!y.has) return x;
        Node r;
        r.has = true;
        r.f = x.f;
        r.l = y.l;
        r.B = x.B + y.B + (long long)(y.f - x.l) * y.f;
        return r;
    }
    Node leaf(int k) {
        Node r;
        if (k >= 1 && k <= n - 2 && a[k] > a[k - 1] && a[k] > a[k + 1]) {
            r.has = true;
            r.f = r.l = k;
            r.B = 0;
        }
        return r;
    }
    void build(int o, int lo, int hi) {
        if (lo == hi) { t[o] = leaf(lo); return; }
        int mid = (lo + hi) / 2;
        build(2 * o, lo, mid);
        build(2 * o + 1, mid + 1, hi);
        t[o] = merge(t[2 * o], t[2 * o + 1]);
    }
    void update(int o, int lo, int hi, int pos) {
        if (lo == hi) { t[o] = leaf(lo); return; }
        int mid = (lo + hi) / 2;
        if (pos <= mid) update(2 * o, lo, mid, pos);
        else update(2 * o + 1, mid + 1, hi, pos);
        t[o] = merge(t[2 * o], t[2 * o + 1]);
    }
    Node query(int o, int lo, int hi, int l, int r) {
        if (l > hi || r < lo) return Node();
        if (l <= lo && hi <= r) return t[o];
        int mid = (lo + hi) / 2;
        return merge(query(2 * o, lo, mid, l, r),
                     query(2 * o + 1, mid + 1, hi, l, r));
    }
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        a = nums;
        t.assign(4 * n, Node());
        build(1, 0, n - 1);
        vector<long long> ans;
        for (auto &q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2];
                if (l + 1 > r - 1) { ans.push_back(0); continue; }
                Node nd = query(1, 0, n - 1, l + 1, r - 1);
                if (!nd.has) { ans.push_back(0); continue; }
                long long res = (long long)(nd.f - l) * (r - nd.f)
                              + (long long)r * (nd.l - nd.f) - nd.B;
                ans.push_back(res);
            } else {
                int idx = q[1];
                a[idx] = q[2];
                for (int k = idx - 1; k <= idx + 1; k++)
                    if (k >= 0 && k < n) update(1, 0, n - 1, k);
            }
        }
        return ans;
    }
};