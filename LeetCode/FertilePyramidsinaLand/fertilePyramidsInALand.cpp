class Solution {
public:
    int count(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> below(n, 0), cur(n, 0);
        int total = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cur[j] = 0;
                } else if (i == m - 1 || j == 0 || j == n - 1) {
                    cur[j] = 1;
                } else {
                    cur[j] = min({below[j - 1], below[j], below[j + 1]}) + 1;
                }
                if (cur[j] > 1) total += cur[j] - 1;
            }
            swap(cur, below);
        }
        return total;
    }

    int countPyramids(vector<vector<int>>& grid) {
        int res = count(grid);
        reverse(grid.begin(), grid.end());
        res += count(grid);
        return res;
    }
};