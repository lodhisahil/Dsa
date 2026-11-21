class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int INF = INT_MAX;
        typedef pair<int, int> pii;
        typedef priority_queue<pii, vector<pii>, greater<pii>> MinHeap;
        vector<MinHeap> rowHeap(m), colHeap(n);
        int ans = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = INF;
                if (i == 0 && j == 0) {
                    cur = 1;
                } else {
                    while (!rowHeap[i].empty() && rowHeap[i].top().second < j)
                        rowHeap[i].pop();
                    if (!rowHeap[i].empty())
                        cur = min(cur, rowHeap[i].top().first + 1);
                    while (!colHeap[j].empty() && colHeap[j].top().second < i)
                        colHeap[j].pop();
                    if (!colHeap[j].empty())
                        cur = min(cur, colHeap[j].top().first + 1);
                }
                if (i == m - 1 && j == n - 1) {
                    ans = (cur == INF) ? -1 : cur;
                }
                if (cur != INF && grid[i][j] > 0) {
                    rowHeap[i].push({cur, j + grid[i][j]});
                    colHeap[j].push({cur, i + grid[i][j]});
                }
            }
        }
        return ans;
    }
};