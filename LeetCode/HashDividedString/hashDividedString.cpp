class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i += k){
            int value = 0;
            for(int j = i; j < i+k; j++){
                value += s[j] - 'a';
            }
            value = value % 26;
            char c = 'a' + value;
            ans.push_back(c);
        }
        return ans;
    }
};