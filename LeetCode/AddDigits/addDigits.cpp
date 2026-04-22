class Solution {
public:
    int digSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        if(num < 10){
            return num;
        }
        return addDigits(digSum(num));
    }
};