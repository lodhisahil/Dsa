class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxLength = 0;
        vector<int> hash(26, 0);

        while(r < s.length()){
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            if((r-l+1) - maxFreq > k){
                hash[s[l] - 'A']--; 
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};