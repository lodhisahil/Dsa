class Solution {
  public:
    void helper(vector<int>& arr, int idx, int sum,vector<int>& ans){
        int n = arr.size();
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        sum += arr[idx];
        helper(arr, idx+1, sum, ans);
        sum -= arr[idx];
        helper(arr, idx+1, sum, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        helper(arr, 0, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};