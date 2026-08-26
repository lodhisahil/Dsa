class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int idx, vector<vector<int>> &allSubsets){
        int n = nums.size();
        if(idx == n){
            allSubsets.push_back(ans);
            return;
        }
        ans.push_back(nums[idx]);
        getAllSubsets(nums, ans, idx+1, allSubsets);
        ans.pop_back();
        int index = idx+1;
        while(index < n && nums[index] == nums[index-1]){
            index++ ;
        }
        getAllSubsets(nums, ans, index, allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};