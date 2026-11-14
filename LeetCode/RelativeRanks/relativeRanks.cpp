class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> copy = score;
        int n = copy.size();
        sort(copy.begin(), copy.end());
        unordered_map<int, string> m;
        int count = 4;
        for(int i = copy.size()-1; i >= 0; i--){
            if(i == n-1){
                m[copy[i]] = "Gold Medal";
            }else if(i == n-2){
                m[copy[i]] = "Silver Medal";
            }else if(i == n-3){
                m[copy[i]] = "Bronze Medal";
            }else{
                m[copy[i]] = to_string(count);
                count ++;
            }
        }
        vector<string> ans;
        for(int i=0; i<n; i++){
            string str = m[score[i]];
            ans.push_back(str);
        }
        return ans;
    }
};