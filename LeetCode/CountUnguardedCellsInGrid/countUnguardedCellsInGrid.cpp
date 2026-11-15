class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> g(m, vector<char>(n, 0));
        for (auto& v : guards) g[v[0]][v[1]] = 1;
        for (auto& v : walls) g[v[0]][v[1]] = 2;
        auto visit = [&](int r, int c, bool& seen) {
            if (g[r][c] == 1) seen = true;
            else if (g[r][c] == 2) seen = false;
            else if (seen) g[r][c] = 3;
        };
        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = 0; j < n; j++) visit(i, j, seen);
            seen = false;
            for (int j = n - 1; j >= 0; j--) visit(i, j, seen);
        }
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = 0; i < m; i++) visit(i, j, seen);
            seen = false;
            for (int i = m - 1; i >= 0; i--) visit(i, j, seen);
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == 0) ans++;
        return ans;
    }
};