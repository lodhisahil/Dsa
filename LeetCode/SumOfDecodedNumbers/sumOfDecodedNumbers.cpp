class Solution {
public:
    static const long long MOD = 1000000007LL;

    long long power(long long base, long long exp) {
        base %= MOD;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = result * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }

    int sumDecoded(vector<long long>& nums) {
        long long total = 0;
        for (long long v : nums) {
            int width = v % 10;
            long long d = v / 10;
            string ds = to_string(d);

            long long x = stoll(ds.substr(0, width));
            long long y = stoll(ds.substr(width));

            total = (total + power(x, y)) % MOD;
        }
        return (int)total;
    }
};