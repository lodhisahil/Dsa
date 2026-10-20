class Solution {
public:
    int m, n;
    int ans = 0;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }
        int gold = grid[r][c];
        grid[r][c] = 0;
        int up = dfs(grid, r - 1, c);
        int down = dfs(grid, r + 1, c);
        int left = dfs(grid, r, c - 1);
        int right = dfs(grid, r, c + 1);
        grid[r][c] = gold;
        return gold + max({up, down, left, right});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};