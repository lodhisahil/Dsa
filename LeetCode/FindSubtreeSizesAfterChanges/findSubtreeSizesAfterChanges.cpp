class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);
        vector<int> newParent(parent.begin(), parent.end());
        vector<int> last(26, -1);
        vector<int> order;
        order.reserve(n);
        struct Frame { int node, idx, saved; };
        vector<Frame> st;
        auto enter = [&](int u) {
            int c = s[u] - 'a';
            if (u != 0 && last[c] != -1) newParent[u] = last[c];
            st.push_back({u, 0, last[c]});
            last[c] = u;
            order.push_back(u);
        };
        enter(0);
        while (!st.empty()) {
            Frame &f = st.back();
            if (f.idx < (int)children[f.node].size()) {
                int v = children[f.node][f.idx++];
                enter(v);
            } else {
                last[s[f.node] - 'a'] = f.saved;
                st.pop_back();
            }
        }
        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }
        return ans;
    }
};