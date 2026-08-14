class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int r = 0;
        int l = 0;
        int minLength = INT_MAX;
        int sIndex = -1;
        while(r < s1.size()){
            int j = 0;
            while(r < s1.size()){
                if(s1[r] == s2[j]){
                    j++;
                }
                if(j == s2.size()){
                    break;
                }
                r++;
            }
            
            if(j != s2.size()){
                break;
            }
            
            int end = r;
            j = s2.size() - 1;
            while(r >= l){
                if(s1[r] == s2[j]){
                    j--;
                }
                if(j < 0){
                    break;
                }
                r--;
            }
            
            if(end - r + 1 < minLength){
                minLength = end - r + 1;
                sIndex = r;
            }
            
            l = r+1;
            r = r+1;
        }
        return sIndex == -1 ? "" : s1.substr(sIndex, minLength);
    }
};