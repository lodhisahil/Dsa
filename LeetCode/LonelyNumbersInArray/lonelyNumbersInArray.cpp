class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        for(auto itr : m){
            if((itr.second == 1) 
            && (m.find(itr.first-1) == m.end()) 
            && (m.find(itr.first+1) == m.end())){
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
};