class Solution {
public:
    int n;
    vector<int> bit;
    vector<vector<int>> adj;
    vector<int> par, heavy, depth, head, pos, sz;
    void upd(int i, int v) {
        for (++i; i <= n; i += i & -i) bit[i] ^= v;
    }
    int pre(int i) {
        int r = 0;
        for (++i; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }
    int rangeXor(int l, int r) {
        return pre(r) ^ (l ? pre(l - 1) : 0);
    }
    int pathXor(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res ^= rangeXor(pos[head[u]], pos[u]);
            u = par[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= rangeXor(pos[u], pos[v]);
        return res;
    }
    vector<bool> palindromePath(int n_, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_;
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        par.assign(n, -1);
        heavy.assign(n, -1);
        depth.assign(n, 0);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 1);
        bit.assign(n + 1, 0);
        vector<int> order;
        order.reserve(n);
        vector<int> st = {0};
        while (!st.empty()) {
            int u = st.back(); st.pop_back();
            order.push_back(u);
            for (int w : adj[u]) {
                if (w != par[u]) {
                    par[w] = u;
                    depth[w] = depth[u] + 1;
                    st.push_back(w);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            int u = order[i];
            if (par[u] != -1) sz[par[u]] += sz[u];
        }
        for (int u : order) {
            int best = -1;
            for (int w : adj[u]) {
                if (w != par[u] && (best == -1 || sz[w] > sz[best])) best = w;
            }
            heavy[u] = best;
        }
        int cur = 0;
        for (int u : order) {
            if (par[u] == -1 || heavy[par[u]] != u) {
                for (int x = u; x != -1; x = heavy[x]) {
                    head[x] = u;
                    pos[x] = cur++;
                }
            }
        }
        for (int i = 0; i < n; ++i) upd(pos[i], 1 << (s[i] - 'a'));
        vector<bool> ans;
        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u; char c;
                ss >> u >> c;
                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                if (delta) {
                    upd(pos[u], delta);
                    s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;
                int m = pathXor(u, v);
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;
    }
};