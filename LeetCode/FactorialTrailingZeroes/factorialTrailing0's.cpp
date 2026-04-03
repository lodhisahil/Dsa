class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        int ans = 0; 
        while(n >= 5){
            n = (n/5);
            ans += n;
        }
        return ans;
    }
};