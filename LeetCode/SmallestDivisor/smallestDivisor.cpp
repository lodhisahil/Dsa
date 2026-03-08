class Solution {
public:
    int divSum(vector<int>& nums, int val){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil((double)(nums[i])/(double)(val));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int st = 1, end = INT_MIN;
        for(int i=0; i<n; i++){
            end = max(end, nums[i]);
        }
        // if(end < threshold){
        //     return 1;
        // }
        while(st <= end){
            int mid = st + (end - st)/2;
            if(divSum(nums, mid) <= threshold){
                end = mid-1;
            }else{
                st = mid + 1;
            }
        }
        return st;
    }
};