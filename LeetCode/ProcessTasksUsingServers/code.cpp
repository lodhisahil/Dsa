class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeQ;
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> busyQ;
        for (int i = 0; i < n; i++) freeQ.push({servers[i], i});
        vector<int> ans(m);
        long long t = 0;
        for (int j = 0; j < m; j++) {
            t = max(t, (long long)j);
            if (freeQ.empty())
                t = max(t, get<0>(busyQ.top()));
            while (!busyQ.empty() && get<0>(busyQ.top()) <= t) {
                auto [ft, w, idx] = busyQ.top();
                busyQ.pop();
                freeQ.push({w, idx});
            }
            auto [w, idx] = freeQ.top();
            freeQ.pop();
            ans[j] = idx;
            busyQ.push({t + tasks[j], w, idx});
        }
        return ans;
    }
};