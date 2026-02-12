class Solution {
public:
    bool check(vector<int>& nums) {
        int flag = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > nums[(i+1)%nums.size()]){
                flag++;
            }
        }
        return flag < 2 ;
    }
};