class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<string, vector<pair<int, int>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int midX = points[i][0] + points[j][0];
                int midY = points[i][1] + points[j][1];
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                long long dist = dx * dx + dy * dy;
                string key = to_string(midX) + "," +
                             to_string(midY) + "," +
                             to_string(dist);
                mp[key].push_back({i, j});
            }
        }
        double ans = 1e18;
        for (auto& [key, v] : mp) {
            for (int a = 0; a < v.size(); a++) {
                for (int b = a + 1; b < v.size(); b++) {
                    int i = v[a].first;
                    int j = v[a].second;
                    int k = v[b].first;
                    int l = v[b].second;
                    // Adjacent sides from point i
                    double side1 = hypot(
                        points[i][0] - points[k][0],
                        points[i][1] - points[k][1]
                    );
                    double side2 = hypot(
                        points[i][0] - points[l][0],
                        points[i][1] - points[l][1]
                    );
                    double area = side1 * side2;
                    ans = min(ans, area);
                }
            }
        }
        return ans == 1e18 ? 0 : ans;
    }
};