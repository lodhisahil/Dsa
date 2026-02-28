class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int ans = INT_MAX;
        int idx = -1;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[st] <= nums[end]){
                if(nums[st] < ans){
                    ans = nums[st];
                    idx = st;
                }
                break;
            }

            //left sorted
            if(nums[st] <= nums[mid]){
                if(nums[st] < ans){
                    ans = nums[st];
                    idx = st;
                }
                st = mid+1;
            }
            //right sorted
            else{
                if(nums[mid] < ans){
                    ans = nums[mid];
                    idx = mid;
                }
                end = mid-1;
            }
        }
        return idx;
    }
};