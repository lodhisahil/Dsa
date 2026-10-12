class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        int suffix = 0;
        for(int i=n-1; i>=0; i--){
            suffix = (suffix + shifts[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + suffix) % 26;
        }
        return s;
    }
};