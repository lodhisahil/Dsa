class Solution {
public:
    int flipLights(int n, int presses) {
        int m = min(n, 6);
        unordered_set<int> seen;
        for (int mask = 0; mask < 16; mask++) {
            int c = __builtin_popcount(mask);
            if (c > presses || (presses - c) % 2 != 0) continue;
            int state = 0;
            for (int i = 1; i <= m; i++) {
                int flip = 0;
                if (mask & 1) flip ^= 1;
                if ((mask & 2) && i % 2 == 0) flip ^= 1;
                if ((mask & 4) && i % 2 == 1) flip ^= 1;
                if ((mask & 8) && (i - 1) % 3 == 0) flip ^= 1;
                state |= (flip << (i - 1));
            }
            seen.insert(state);
        }
        return seen.size();
    }
};