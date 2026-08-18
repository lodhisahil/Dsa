class Solution {
public:
    int find(vector<int>& parent, int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent, parent[x]);
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {

        int n = deadline.size();

        vector<pair<int,int>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Highest profit first
        sort(jobs.rbegin(), jobs.rend());

        int maxDeadline = 0;
        for(int d : deadline) {
            maxDeadline = max(maxDeadline, d);
        }

        // parent[i] = latest available slot <= i
        vector<int> parent(maxDeadline + 1);

        for(int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int count = 0;
        int totalProfit = 0;

        for(auto& job : jobs) {

            int p = job.first;
            int d = job.second;

            int slot = find(parent, d);

            if(slot > 0) {
                count++;
                totalProfit += p;

                // slot is now occupied
                parent[slot] = find(parent, slot - 1);
            }
        }

        return {count, totalProfit};
    }
};