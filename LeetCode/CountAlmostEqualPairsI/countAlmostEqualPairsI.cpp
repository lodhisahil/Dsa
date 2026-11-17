class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            string t = to_string(nums[i]);
            v[i] = string(7 - t.size(), '0') + t;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> diff;
                for (int p = 0; p < 7; p++) {
                    if (v[i][p] != v[j][p]) {
                        diff.push_back(p);
                        if (diff.size() > 2) break;
                    }
                }
                if (diff.empty()) {
                    ans++;
                } else if (diff.size() == 2) {
                    int p = diff[0], q = diff[1];
                    if (v[i][p] == v[j][q] && v[i][q] == v[j][p]) ans++;
                }
            }
        }
        return ans;
    }
};