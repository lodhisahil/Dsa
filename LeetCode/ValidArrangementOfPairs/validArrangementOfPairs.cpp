class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> degree; // out - in

        for (auto& p : pairs) {
            adj[p[0]].push_back(p[1]);
            degree[p[0]]++;
            degree[p[1]]--;
        }

        // Start node: out - in == 1, warna koi bhi node (circuit case)
        int start = pairs[0][0];
        for (auto& [node, d] : degree) {
            if (d == 1) {
                start = node;
                break;
            }
        }

        // Iterative Hierholzer's algorithm
        vector<int> path;
        vector<int> st;
        st.push_back(start);

        while (!st.empty()) {
            int u = st.back();
            if (!adj[u].empty()) {
                int v = adj[u].back();
                adj[u].pop_back();
                st.push_back(v);
            } else {
                path.push_back(u);
                st.pop_back();
            }
        }

        reverse(path.begin(), path.end());

        vector<vector<int>> result;
        result.reserve(pairs.size());
        for (int i = 0; i + 1 < (int)path.size(); i++) {
            result.push_back({path[i], path[i + 1]});
        }
        return result;
    }
};