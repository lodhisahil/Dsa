class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int val : nums){
            maxi = max(val, maxi);
            mini = min(val, mini);
        }
        return gcd(maxi, mini);
    }
};