class Solution {
public:
    string minWindow(string s, string t) {
        int r = 0;
        int l = 0;
        int count = 0;
        int minLength = INT_MAX;
        int sIndex = -1;
        vector<int>hash(256, 0);
        for(char c : t){
            hash[c]++;
        } 
        while(r<s.size()){
            if(hash[s[r]] > 0){
                count++;
            }
            hash[s[r]]--;
            while(count == t.size()){
            if(minLength > r - l + 1){
                    minLength = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLength);
    }
};