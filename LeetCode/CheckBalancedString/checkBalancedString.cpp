class Solution {
public:
    bool isBalanced(string num) {
        int oddSum = 0;
        int evenSum = 0;
        for(int i=0; i<num.length(); i++){
            if(i % 2 != 0){
                oddSum += num[i] - 48;
            }else{
                evenSum += num[i] - 48;
            }
        }
        return oddSum == evenSum;
    }
};