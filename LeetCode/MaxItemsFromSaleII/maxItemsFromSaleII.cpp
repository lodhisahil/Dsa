class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<long long> cnt(n + 1, 0), M(n + 1, 0);
        for (auto &it : items) cnt[it[0]]++;
        for (int f = 1; f <= n; f++)
            for (int g = f; g <= n; g += f)
                M[f] += cnt[g];
        vector<pair<long long, long long>> v;
        long long m = LLONG_MAX;
        for (auto &it : items) {
            long long d = M[it[0]] - 1;
            v.push_back({it[1], d});
            m = min(m, (long long)it[1]);
        }
        sort(v.begin(), v.end());
        long long R = budget, A = 0;
        for (auto &[p, d] : v) {
            if (p >= 2 * m) break;
            if (d == 0) continue;
            long long a = min(d, R / p);
            A += a;
            R -= a * p;
            if (a < d) break;
        }
        return 2 * A + R / m;
    }
};