class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    int countValidSequences(int n, int k) {
        vector<long long> fact(n + 1, 1);
        vector<long long> invFact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
        auto nCr = [&](int a, int b) -> long long {
            if (b < 0 || b > a) {
                return 0;
            }
            return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };
        long long total = nCr(n - 1, k - 1);
        long long odd = 0;
        if ((n - k) % 2 == 0) {
            odd = nCr((n + k - 2) / 2, k - 1);
        }
        return (total - odd + MOD) % MOD;
    }
};