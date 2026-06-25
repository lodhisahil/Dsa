class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int duplicate = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += abs(nums[i]);
            int index = abs(nums[i]) - 1;

            if(nums[index] < 0){
                duplicate = abs(nums[i]);
            }else{
                nums[index] *= -1;
            }
        }
        int thSum = (n * (n+1)) / 2;
        int missing = thSum - (sum - duplicate);
        return {duplicate, missing};
    }
};