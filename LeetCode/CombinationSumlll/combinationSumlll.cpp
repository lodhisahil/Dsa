class Solution {
public:
    void helper(int k, int n, int idx, vector<int>& currArray, vector<vector<int>>& ans){
        if(currArray.size() == k){
            if(n == 0){
                ans.push_back(currArray);
            }
            return;
        }
        if(idx > 9 || n < 0){
            return;
        }
        //pick element
        currArray.push_back(idx);
        helper(k, n - idx, idx + 1, currArray, ans);
        currArray.pop_back();
        helper(k, n, idx + 1, currArray, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currArray;
        helper(k, n, 1, currArray, ans);
        return ans;
    }
};