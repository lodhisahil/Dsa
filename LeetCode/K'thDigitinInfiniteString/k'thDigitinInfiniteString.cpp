class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9) {
            return (int)k;
        }
        k -= 9;
        long long base = 1;
        int digits = 2;
        while (true) {
            long long blocks = 9 * base;
            long long total = blocks * 10 * digits;
            if (k > total) {
                k -= total;
                base *= 10;
                digits++;
            } else {
                break;
            }
        }
        long long blockIndex = (k - 1) / (10LL * digits);
        long long pos = (k - 1) % (10LL * digits);
        long long b = base + blockIndex;
        long long numIndex = pos / digits;
        int digitIndex = pos % digits;
        long long num;
        if (b % 2 == 0) {
            num = b * 10 + numIndex;
        } else {
            num = b * 10 + 9 - numIndex;
        }
        string s = to_string(num);
        return s[digitIndex] - '0';
    }
};