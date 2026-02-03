class Solution {
public:

    void helper(int idx, vector<int>& digits){
        if(idx < 0){
            digits.insert(digits.begin(), 1);
            return;
        }
        if(digits[idx] < 9){
            digits[idx] += 1;
            return ;
        } else {
            digits[idx] = 0;
            helper(idx-1, digits);
        }     
        return ;
    }
    vector<int> plusOne(vector<int>& digits) {
        helper(digits.size()-1, digits);
        return digits;
    }
};