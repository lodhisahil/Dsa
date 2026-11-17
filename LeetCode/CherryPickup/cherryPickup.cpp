class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        const int NEG = INT_MIN / 2;
        int T = 2 * n - 1;
        vector<vector<int>> cur(n, vector<int>(n, NEG)), nxt;
        cur[0][0] = grid[0][0];
        for (int t = 1; t < T; t++) {
            nxt.assign(n, vector<int>(n, NEG));
            for (int r1 = max(0, t - (n - 1)); r1 <= min(n - 1, t); r1++) {
                int c1 = t - r1;
                if (grid[r1][c1] == -1) continue;
                for (int r2 = max(0, t - (n - 1)); r2 <= min(n - 1, t); r2++) {
                    int c2 = t - r2;
                    if (grid[r2][c2] == -1) continue;
                    int best = cur[r1][r2];// dono left se
                    if (r1 > 0) best = max(best, cur[r1 - 1][r2]);// walker1 up se
                    if (r2 > 0) best = max(best, cur[r1][r2 - 1]);// walker2 up se
                    if (r1 > 0 && r2 > 0) best = max(best, cur[r1 - 1][r2 - 1]);
                    if (best == NEG) continue;
                    int gain = grid[r1][c1];
                    if (r1 != r2) gain += grid[r2][c2];
                    nxt[r1][r2] = best + gain;
                }
            }
            cur.swap(nxt);
        }
        return max(0, cur[n - 1][n - 1]);
    }
};