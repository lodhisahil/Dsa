class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int ans = INT_MAX;
        while(r < nums.size()){
            target -= nums[r];
            r++;
            while(target <= 0){
                ans = min(ans, r - l);
                target += nums[l];
                l++;
            }         
        }
        return ans == INT_MAX ? 0 : ans;
    }
};