class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const long long MOD = 1e9 + 7;
        int n = conversions.size() + 1;
        vector<vector<pair<int,int>>> g(n);
        for (auto &c : conversions)
            g[c[0]].push_back({c[1], c[2]});
        vector<int> res(n, 0);
        res[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &[v, w] : g[u]) {
                res[v] = (long long)res[u] * w % MOD;
                q.push(v);
            }
        }
        return res;
    }
};