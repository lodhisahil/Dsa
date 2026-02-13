class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int> temp;
        // int n = nums.size();
        // k = k % n;
        // for(int i=0; i<n; i++){
        //     temp.push_back(nums[i]);
        // }
        // int tp = n-k, np = 0;
        // while(tp < n){
        //     nums[np] = temp[tp];
        //     tp++;
        //     np++;
        // }
        // tp = 0;
        // np = k;
        // while(tp < n-k){
        //     nums[np] = temp[tp];
        //     np++;
        //     tp++;
        // }
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};