class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash (255, -1);
        int l = 0, r = 0;
        int length = 0;
        int maxLength = 0;
        while(r <= s.length()){
            if(hash[s[r]] != -1){// it means it is in the map
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            maxLength = max(maxLength, length);
            length = r - l + 1;
            hash[s[r]] = r;
            r++;
        }
        return maxLength;
    }
};