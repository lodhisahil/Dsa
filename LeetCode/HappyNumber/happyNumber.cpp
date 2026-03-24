class Solution {
public:
    int squareSumOfDigit(int num){
        int sum = 0;
        while(num > 0){
            int d = num % 10;
            sum += d * d;
            num = num / 10;
        }
        return sum;
    }
    /*bool isHappy(int n) {
        if(n < 0) return false;
        unordered_set<int> s;
        while(s.find(n) == s.end()){
            s.insert(n);
            n = squareSumOfDigit(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
    */
    bool isHappy(int n) {
        if(n < 0) return false;
        int slowSum = n;
        int fastSum = squareSumOfDigit(n);
        if(slowSum == 1 || fastSum == 1){
            return true;
        }
        while(slowSum != fastSum){
            slowSum = squareSumOfDigit(slowSum);
            fastSum = squareSumOfDigit(squareSumOfDigit(fastSum));
            if(slowSum == 1 || fastSum == 1){
            return true;
        }
        }
        return false;
    }
};