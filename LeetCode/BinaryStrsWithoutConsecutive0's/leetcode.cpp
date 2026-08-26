class Solution {
public:
    void helper(int n, vector<string>& ans, string& s, int idx){
        if(idx == n){
            ans.push_back(s);
            return;
        }
        // pick 1s
        s += "1";
        helper(n, ans, s, idx+1);
        s.pop_back();

        // only pick if there is not 0 behind it
        if(idx == 0 || s[idx-1] != '0'){
            s += "0";
            helper(n, ans, s, idx+1);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s;
        helper(n, ans, s, 0);
        return ans;        
    }
};