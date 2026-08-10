class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int r = 0;
        int l = 0;
        int count = 0;
        vector<int> hash(3, -1);
        while(r < n){
            hash[s[r] - 'a'] = r;
            if( hash[0] >= 0 && hash[1] >= 0 && hash[2] >= 0 ){
                count += min(hash[0], min(hash[1], hash[2])) + 1;
            }
            r++;
        }
        return count;
    }
};