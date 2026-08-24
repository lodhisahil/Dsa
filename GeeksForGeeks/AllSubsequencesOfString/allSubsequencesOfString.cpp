class Solution {
  public:
    void helper(string &s, int idx, vector<string> &ans, string &currStr){
        int n = s.length();
        if(idx >= n){
            ans.push_back(currStr);
            return;
        }
        currStr += s[idx];
        helper(s, idx + 1, ans, currStr);
        currStr.erase(currStr.length()-1);
        helper(s, idx + 1, ans, currStr);
    }
    vector<string> powerSet(string &s) {
        // Code here
        string currStr = "";
        vector<string> ans;
        helper(s, 0, ans, currStr);
        sort(ans.begin(), ans.end());
        return ans;
    }
};