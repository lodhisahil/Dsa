class Solution {
public:
    string helper(string str){
        string ans = "";
        for(char c : str){
            if(c == '#'){
                if(ans.size()>0){
                    ans.pop_back();
                }
            } else {
                ans.push_back(c);
            }
            
        }
        return ans;
    }

    bool backspaceCompare(string s, string t) {
        return helper(s) == helper(t);
    }
};