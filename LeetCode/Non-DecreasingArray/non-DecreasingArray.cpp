class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i+1 < nums.size() && nums[i] > nums[i+1]){
                if(i-1 >= 0 && nums[i] >= nums[i-1] && nums[i+1] < nums[i-1]){
                    nums[i+1] = nums[i];
                }else{
                    nums[i] = nums[i+1];
                }
                break;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(i+1 < nums.size() && nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }
};