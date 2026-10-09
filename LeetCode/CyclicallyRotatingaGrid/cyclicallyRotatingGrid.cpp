class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for (int layer = 0; layer < min(m, n) / 2; layer++) {
            int top = layer;
            int left = layer;
            int bottom = m - 1 - layer;
            int right = n - 1 - layer;
            vector<int> arr;
            for (int i = top; i <= bottom; i++) {
                arr.push_back(grid[i][left]);
            }
            for (int j = left + 1; j <= right; j++) {
                arr.push_back(grid[bottom][j]);
            }
            for (int i = bottom - 1; i >= top; i--) {
                arr.push_back(grid[i][right]);
            }
            for (int j = right - 1; j > left; j--) {
                arr.push_back(grid[top][j]);
            }
            int len = arr.size();
            int shift = k % len;
            int idx = (len - shift) % len;
            for (int i = top; i <= bottom; i++) {
                grid[i][left] = arr[idx];
                idx = (idx + 1) % len;
            }
            for (int j = left + 1; j <= right; j++) {
                grid[bottom][j] = arr[idx];
                idx = (idx + 1) % len;
            }
            for (int i = bottom - 1; i >= top; i--) {
                grid[i][right] = arr[idx];
                idx = (idx + 1) % len;
            }
            for (int j = right - 1; j > left; j--) {
                grid[top][j] = arr[idx];
                idx = (idx + 1) % len;
            }
        }
        return grid;
    }
};