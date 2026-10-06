class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int totalMasks = 1 << n;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[req_skills[i]] = i;
        }
        vector<int> personMask(people.size());
        for (int i = 0; i < people.size(); i++) {
            for (string skill : people[i]) {
                personMask[i] |= (1 << mp[skill]);
            }
        }
        vector<vector<int>> dp(totalMasks);
        vector<bool> reachable(totalMasks, false);
        reachable[0] = true;
        for (int i = 0; i < people.size(); i++) {
            int pmask = personMask[i];
            vector<vector<int>> nextDp = dp;
            vector<bool> nextReachable = reachable;
            for (int mask = 0; mask < totalMasks; mask++) {
                if (!reachable[mask]) {
                    continue;
                }
                int newMask = mask | pmask;
                vector<int> candidate = dp[mask];
                candidate.push_back(i);
                if (!nextReachable[newMask] || candidate.size() < nextDp[newMask].size()) {
                    nextDp[newMask] = candidate;
                    nextReachable[newMask] = true;
                }
            }
            dp = nextDp;
            reachable = nextReachable;
        }
        return dp[totalMasks - 1];
    }
};