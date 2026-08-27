class Solution {
public:
    void helper(string& digits, vector<string>& ans, string& s, int idx, unordered_map<int, vector<char>>& m){
        int n = digits.size();
        if(idx == n){
            ans.push_back(s);
            return;
        }
        int key = digits[idx] - '0';
        for(int i=0; i<m[key].size(); i++){
            s.push_back(m[key][i]);
            helper(digits, ans, s, idx + 1, m);
            s.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s = "";
        unordered_map<int, vector<char>> m;
        m[2] = {'a', 'b', 'c'};
        m[3] = {'d', 'e', 'f'};
        m[4] = {'g', 'h', 'i'};
        m[5] = {'j', 'k', 'l'};
        m[6] = {'m', 'n', 'o'};
        m[7] = {'p', 'q', 'r', 's'};
        m[8] = {'t', 'u', 'v'};
        m[9] = {'w', 'x', 'y', 'z'};

        helper(digits, ans, s, 0, m);
        return ans;
    }
};