class Solution {
  public:
    long long power(int base, int exp){
        long long result = 1;
        for(int i=0; i<exp; i++){
            result *= base;
        }
        return result;
    }
  
    int nthRoot(int n, int m) {
        // Code here
        if(m == 0){
            return 0;
        }
        int ans = -1;
        int st = 1;
        int end = m;
        while(st <= end){
            long long mid = st + (end - st)/2;
            long long val = power(mid, n);
            if(val == m){
                return mid;
            }else if(val > m){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return -1;
    }
};