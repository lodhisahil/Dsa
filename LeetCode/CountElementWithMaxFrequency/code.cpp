class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxFreq = INT_MIN;
        for(int num : nums){
            m[num]++;
            maxFreq = max(maxFreq, m[num]);
        }
        int count = 0;
        for(auto it : m){
            if(it.second == maxFreq){
                count += it.second;
            } 
        }
        return count;
    }
};