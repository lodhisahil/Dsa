class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int ans = 0;
        if( n < 2){
            return n;
        }
        int st = 1;
        int end = n/2;
        while(st <= end){
            long long mid = st + (end - st)/2;
            if( mid*mid <= n){
                ans = (int)mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};