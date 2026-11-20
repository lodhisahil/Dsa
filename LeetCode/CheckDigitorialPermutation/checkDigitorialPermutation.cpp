class Solution {
public:
    bool isDigitorialPermutation(int n) {
        long long fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int cnt[10] = {0};
        long long s = 0;
        int t = n;
        while (t > 0) {
            int d = t % 10;
            cnt[d]++;
            s += fact[d];
            t /= 10;
        }
        int cnt2[10] = {0};
        long long u = s;
        while (u > 0) {
            cnt2[u % 10]++;
            u /= 10;
        }
        for (int d = 0; d < 10; d++) {
            if (cnt[d] != cnt2[d]) return false;
        }
        return true;
    }
};