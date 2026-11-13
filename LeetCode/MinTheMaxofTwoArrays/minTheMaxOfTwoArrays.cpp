class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long lcm = (1LL * divisor1 * divisor2) / __gcd(divisor1, divisor2);
        long long low = 1;
        long long high = 2000000000LL;
        long long ans = high;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long count1 = mid - mid / divisor1;
            long long count2 = mid - mid / divisor2;
            long long countBoth = mid - mid / lcm;
            if(count1 >= uniqueCnt1 &&
               count2 >= uniqueCnt2 &&
               countBoth >= (long long)uniqueCnt1 + uniqueCnt2) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};