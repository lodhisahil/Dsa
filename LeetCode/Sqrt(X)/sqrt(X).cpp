class Solution {
public:
    int mySqrt(int x) {
        long long st = 0;
        long long end = x;
        long long ans = 0;
        while(st <= end){
            long long mid = st + (end-st)/2;
            if(mid*mid == x){
                return mid;
            }else if(mid*mid < x){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};