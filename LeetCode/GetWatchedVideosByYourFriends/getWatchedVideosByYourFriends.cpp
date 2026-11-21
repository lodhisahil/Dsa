class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<bool> visited(n, false);
        vector<int> cur = {id};
        visited[id] = true;
        for (int d = 0; d < level; d++) {
            vector<int> next;
            for (int u : cur) {
                for (int v : friends[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        next.push_back(v);
                    }
                }
            }
            cur = move(next);
        }
        unordered_map<string, int> freq;
        for (int p : cur) {
            for (const string& v : watchedVideos[p]) {
                freq[v]++;
            }
        }
        vector<pair<int, string>> items;
        for (auto& kv : freq) items.push_back({kv.second, kv.first});
        sort(items.begin(), items.end());
        vector<string> ans;
        for (auto& it : items) ans.push_back(it.second);
        return ans;
    }
};