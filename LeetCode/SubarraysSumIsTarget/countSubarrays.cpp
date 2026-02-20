class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int, int> m;
        int count = 0;
        for(int i=0; i<n; i++){
            if(prefix[i] == k){
                count++;
            }
            int val = prefix[i]-k;
            if(m.find(val) != m.end()){
                count += m[val];
            }
            if(m.find(prefix[i]) == m.end()){
                m[prefix[i]] = 0;
            }
            m[prefix[i]]++;
        }
        return count;
    }
};