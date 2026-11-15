class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[nums[i]].push_back(i);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long len = r[i] - i - 1;
            if (len <= 0) continue;
            vector<int>& p = pos[nums[i]];
            long long eq = lower_bound(p.begin(), p.end(), r[i]) - upper_bound(p.begin(), p.end(), i);
            ans += len - eq;
        }
        return ans;
    }
};