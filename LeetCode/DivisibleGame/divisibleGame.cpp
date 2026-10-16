class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int M = *max_element(nums.begin(), nums.end());
        vector<int> spf(M + 1);
        iota(spf.begin(), spf.end(), 0);
        for (long long i = 2; i * i <= M; i++){
            if (spf[i] == i){
                for (long long j = i * i; j <= M; j += i){
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        set<int> primes = {2};
        for (int x : nums) {
            while (x > 1) {
                int p = spf[x];
                primes.insert(p);
                while (x % p == 0) x /= p;
            }
        }
        long long bestDiff = LLONG_MIN;
        int bestK = 2;
        for (int k : primes) {
            long long cur = 0, best = LLONG_MIN;
            bool first = true;
            for (int x : nums) {
                long long v = (x % k == 0) ? x : -x;
                if (first || cur < 0) cur = v;
                else cur += v;
                first = false;
                best = max(best, cur);
            }
            if (best > bestDiff) {
                bestDiff = best;
                bestK = k;
            }
        }
        long long ans = ((bestDiff % MOD) * bestK) % MOD;
        if (ans < 0) ans += MOD;
        return (int)ans;
    }
};