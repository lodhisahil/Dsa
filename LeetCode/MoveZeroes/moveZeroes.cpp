class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        //naive approach 
        // vector<int> temp;
        // for(int i=0; i<n; i++){
        //     if(nums[i] != 0){
        //         temp.push_back(nums[i]);
        //     }
        // }
        // for(int j=0; j<temp.size(); j++){
        //     nums[j] = temp[j];
        // }
        // for(int k=temp.size(); k<n; k++){
        //     nums[k] = 0;
        // }
        
        //optimal approach
        int j = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        } 
        if(j == -1){
            return;
        }
        for(int i=j+1; i<n; i++){
            if(nums[i] != 0){
                swap(nums[j], nums[i]);
                j++;
            }
        }
    }
};