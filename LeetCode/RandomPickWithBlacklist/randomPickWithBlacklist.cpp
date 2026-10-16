class Solution {
    int k;
    unordered_map<int, int> mp;
public:
    Solution(int n, vector<int>& blacklist) {
        k = n - blacklist.size();
        unordered_set<int> bset(blacklist.begin(), blacklist.end());
        int w = k;
        for (int b : blacklist) {
            if (b < k) {
                while (bset.count(w)) w++;
                mp[b] = w++;
            }
        }
    }
    int pick() {
        int r = rand() % k;
        auto it = mp.find(r);
        return it == mp.end() ? r : it->second;
    }
};