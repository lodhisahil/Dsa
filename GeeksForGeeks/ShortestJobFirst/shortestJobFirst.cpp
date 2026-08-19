class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        int wtTime = 0;
        int compTime = 0;
        for(int i = 0; i < bt.size(); i ++){
            wtTime += compTime;
            compTime += bt[i];
        }
        return wtTime / bt.size();
    }
};