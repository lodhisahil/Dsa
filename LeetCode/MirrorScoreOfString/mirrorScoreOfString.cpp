class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>> st(26);
        long long score = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            int m = 25 - c;
            if (!st[m].empty()) {
                score += i - st[m].back();
                st[m].pop_back();
            } else {
                st[c].push_back(i);
            }
        }
        return score;
    }
};