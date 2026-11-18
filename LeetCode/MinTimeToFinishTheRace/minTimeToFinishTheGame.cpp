class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        const int MAXX = 20;
        const long long INF = 1e18;
        vector<long long> best(MAXX + 1, INF);

        for (auto& t : tires) {
            long long f = t[0], r = t[1];
            long long lap = f, sum = 0;
            for (int x = 1; x <= MAXX; x++) {
                if (lap > f + changeTime) break;
                sum += lap;
                best[x] = min(best[x], sum);
                lap *= r;
            }
        }

        vector<long long> dp(numLaps + 1, INF);
        dp[0] = -changeTime;
        for (int i = 1; i <= numLaps; i++) {
            for (int x = 1; x <= min(i, MAXX); x++) {
                if (best[x] == INF) break;
                dp[i] = min(dp[i], dp[i - x] + best[x] + changeTime);
            }
        }
        return (int)dp[numLaps];
    }
};