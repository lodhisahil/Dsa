class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xxor = 0;
        for(int i=0; i<=nums.size()-1; i++){
            xxor = xxor ^ nums[i];
        }
        int rightMost = xxor & (-xxor);
        int b1 = 0, b2 = 0;
        for(int i=0; i<=nums.size()-1; i++){
            if(nums[i] & rightMost){
                b1 = b1 ^ nums[i];
            }else{
                b2 = b2 ^ nums[i];
            }
        }
        return {b1, b2};
    }
};