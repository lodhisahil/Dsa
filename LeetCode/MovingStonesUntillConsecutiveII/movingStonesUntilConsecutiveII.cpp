class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maxMoves = max(stones[n - 1] - stones[1] - (n - 2), stones[n - 2] - stones[0] - (n - 2));

        int minMoves = n;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (stones[i] - stones[j] + 1 > n) j++;
            int inWindow = i - j + 1;
            if (inWindow == n - 1 && stones[i] - stones[j] + 1 == n - 1) {
                minMoves = min(minMoves, 2);
            } else {
                minMoves = min(minMoves, n - inWindow);
            }
        }
        return {minMoves, maxMoves};
    }
};