class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }
        if (!stopToBuses.count(source) || !stopToBuses.count(target)) return -1;
        vector<bool> busVisited(n, false);
        unordered_set<int> stopVisited;
        queue<pair<int, int>> q; // {bus, buses taken till now}

        stopVisited.insert(source);
        for (int bus : stopToBuses[source]) {
            busVisited[bus] = true;
            q.push({bus, 1});
        }
        while (!q.empty()) {
            auto [bus, cnt] = q.front();
            q.pop();
            for (int stop : routes[bus]) {
                if (stop == target) return cnt;
                if (stopVisited.count(stop)) continue;
                stopVisited.insert(stop);
                for (int nextBus : stopToBuses[stop]) {
                    if (!busVisited[nextBus]) {
                        busVisited[nextBus] = true;
                        q.push({nextBus, cnt + 1});
                    }
                }
            }
        }
        return -1;
    }
};