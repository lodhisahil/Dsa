class Solution {
public:
    int helper(vector<vector<int>>& grid, int row, int col,
               vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (row == m - 1 && col == n - 1) {
            return grid[row][col];
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int right = INT_MAX;
        int down = INT_MAX;
        if (col < n - 1) {
            right = helper(grid, row, col + 1, dp);
        }
        if (row < m - 1) {
            down = helper(grid, row + 1, col, dp);
        }
        dp[row][col] = grid[row][col] + min(right, down);
        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, 0, 0, dp);
    }
};