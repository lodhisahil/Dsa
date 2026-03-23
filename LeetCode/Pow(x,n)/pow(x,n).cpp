class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)return 0;
        if(n == 0)return 1;
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn = -1 * nn;
        while(nn > 0){
            if(nn % 2 == 0){//even
                x = x * x;
                nn = nn / 2;
            }else {
                ans = ans * x;
                nn = nn - 1;
            }
        }
        if(n < 0) ans = (double)(1.0) / (double)ans;
        return ans;
    }
};


//############################## recursive approach ##############################
class Solution {
public:
    double power(double x, long n){
        if(n == 0)return 1;
        if(n == 1)return x;
        if(n % 2 == 0){
            return power(x * x, n / 2);
        }
        return x * power(x, n - 1);
    }
    double myPow(double x, int n) {
        long long num = n;
        if(num < 0){
            return 1.0 / power(x,-1 * num);
        }
        return power(x, num);
    }
};