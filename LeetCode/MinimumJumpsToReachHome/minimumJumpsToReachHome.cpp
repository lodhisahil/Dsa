class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int limit = 6000;
        vector<bool> blocked(limit + 1, false);
        for (int pos : forbidden) {
            blocked[pos] = true;
        }
        vector<vector<bool>> visited(
            limit + 1,
            vector<bool>(2, false)
        );
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        int jumps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int pos = q.front().first;
                int last = q.front().second;
                q.pop();
                if (pos == x) {
                    return jumps;
                }
                int next = pos + a;
                if (next <= limit &&
                    !blocked[next] &&
                    !visited[next][0]) {
                    visited[next][0] = true;
                    q.push({next, 0});
                }
                // Backward jump - Cannot jump backward twice
                if (last == 0) {
                    next = pos - b;
                    if (next >= 0 &&
                        !blocked[next] &&
                        !visited[next][1]) {
                        visited[next][1] = true;
                        q.push({next, 1});
                    }
                }
            }
            jumps++;
        }
        return -1;
    }
};