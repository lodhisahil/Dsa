class Solution {
public:
    int helper(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int count = 0;
        unordered_map<int, int> m;
        while(r < nums.size()){
            m[nums[r]]++;
            while(m.size() > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
                }
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (helper(nums, k) - helper(nums, k-1));
    }
};