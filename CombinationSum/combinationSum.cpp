class Solution {
public:

    set<vector<int>> s;

    void getAllCombin(vector<int>& nums, int idx, int target, vector<int> &combin, vector<vector<int>> &ans){
        if(idx == nums.size() || target < 0){
            return;
        }

        if(target == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
                return;
            
        }

        combin.push_back(nums[idx]);
        getAllCombin(nums, idx+1, target-nums[idx], combin, ans);//once inclusion
        getAllCombin(nums, idx, target-nums[idx], combin, ans);//multiple inclusion
        combin.pop_back();//exclude the element to meake the combin empty for the exclusion call

        getAllCombin(nums, idx+1, target, combin, ans);// exclusion call
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combin;
        vector<vector<int>> ans;
        getAllCombin(nums, 0, target, combin, ans);

        return ans;
    }
};