class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i<n-1; i++){
            if(nums[i+1] - nums[i] > 1){
                int insert = nums[i] + 1;
                for(int j = 0; j<nums[i+1] - nums[i] - 1; j++){
                    ans.push_back(insert);
                    insert++;
                }
            }
        }
        return ans;
    }
};