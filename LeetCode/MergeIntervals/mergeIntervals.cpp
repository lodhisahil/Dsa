class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j = 0;
        int i = 1;
        while(i < n){
            if(ans[j][1] >= intervals[i][0]){
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
                j++;
            }
            i++;
        }
        return ans;
    }
};