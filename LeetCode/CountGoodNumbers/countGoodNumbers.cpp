class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        if (exp == 0) return 1;
        long long half = power(base, exp / 2);
        half = (half * half) % MOD;
        if (exp % 2 == 1) {
            half = (half * base) % MOD;
        }
        return half;
    }
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        // Even indices: 0,2,4,6,8 = 5 choices
        // Odd indices: 2,3,5,7 = 4 choices
        long long ans = power(5, evenPos);
        ans = (ans * power(4, oddPos)) % MOD;
        return ans;
    }
};