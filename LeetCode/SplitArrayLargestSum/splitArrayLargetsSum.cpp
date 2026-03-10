class Solution {
public:
    bool possible(vector<int>& nums, int mid, int k){
        int sum = 0, parts = 1;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }else{
                parts++;
                sum = nums[i];
            }
        }
        return parts <= k ? true : false; 
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        int st = INT_MIN;
        int end = 0;
        for(int i=0; i<n; i++){
            end += nums[i];
            st = max(st, nums[i]);
        }
        while(st <= end){
            int mid = st + (end - st)/2;
            if(possible(nums, mid, k)){
                end = mid - 1;
                ans = mid;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
};