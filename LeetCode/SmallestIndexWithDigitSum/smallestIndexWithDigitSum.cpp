class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num = num/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int digiSum = digitSum(nums[i]);
            if(i == digiSum){
                return i;
            }
        }
        return -1;
    }
};