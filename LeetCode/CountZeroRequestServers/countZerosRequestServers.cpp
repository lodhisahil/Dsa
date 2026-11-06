class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int q = queries.size();
        vector<pair<int, int>> qs(q);
        for (int i = 0; i < q; i++) qs[i] = {queries[i], i};
        sort(qs.begin(), qs.end());
        vector<int> cnt(n + 1, 0);
        int active = 0;
        int left = 0, right = 0;
        int m = logs.size();
        vector<int> ans(q);
        for (auto& [t, idx] : qs) {
            while (right < m && logs[right][1] <= t) {
                if (cnt[logs[right][0]]++ == 0) active++;
                right++;
            }
            while (left < right && logs[left][1] < t - x) {
                if (--cnt[logs[left][0]] == 0) active--;
                left++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};