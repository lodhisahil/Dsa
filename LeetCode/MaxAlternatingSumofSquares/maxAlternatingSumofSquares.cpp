class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        long long score = 0;
        for(int i=0; i<n; i++){
            long long square = (long long) nums[i] * nums[i];
            if(i < n/2){
                score -= square;
            }else{
                score += square;
            }
        }
        return score;
    }
};