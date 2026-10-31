class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        vector<vector<long long>> right(m, vector<long long>(n, 0));
        vector<vector<long long>> down(m, vector<long long>(n, 0));
        if (n > 1) {
            right[0][1] = 1;
        }
        if (m > 1) {
            down[1][0] = 1;
        }
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == m - 1 && j == n - 1) {
                    ans = (right[i][j] + down[i][j]) % MOD;
                    return ans;
                }
                if (grid[i][j] == 0) {
                    // Empty cell
                    long long ways = (right[i][j] + down[i][j]) % MOD;
                    // Move right
                    if (j + 1 < n) {
                        right[i][j + 1] = (right[i][j + 1] + ways) % MOD;
                    }
                    // Move down
                    if (i + 1 < m) {
                        down[i + 1][j] = (down[i + 1][j] + ways) % MOD;
                    }
                } 
                else {
                    // Mirror cell
                    if (i + 1 < m) {
                        down[i + 1][j] = (down[i + 1][j] + right[i][j]) % MOD;
                    }
                    if (j + 1 < n) {
                        right[i][j + 1] = (right[i][j + 1] + down[i][j]) % MOD;
                    }
                }
            }
        }
        return ans;
    }
};