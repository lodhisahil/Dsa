class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }
        long long ans = 0;
        // 1 commas
        if(n > 999){
            ans += min(n, 999999LL) - 999;
        }
        // 2 commas 
        if(n > 999999){
            ans += (min(n, 999999999LL) - 999999) * 2;
        }
        // 3 commas
        if(n > 999999999){
            ans += (min(n, 999999999999LL) - 999999999) * 3;
        }
        // 4 commas
        if(n > 999999999999){
            ans += (min(n, 999999999999999LL) - 999999999999) * 4;
        }
        // 5 commas
        if(n > 999999999999999){
            ans += (min(n, 999999999999999999LL) - 999999999999999) * 5;
        }

        return ans;
    }
};