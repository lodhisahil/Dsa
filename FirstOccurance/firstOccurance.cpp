class Solution {
public:
    int strStr(string haystack, string needle) {
        int ned = 0, hay = 0;
        int start = 0;
        while(hay < haystack.size()){
            if(haystack[hay] == needle[ned]){
                if(ned == 0) start = hay;
                ned++;
                hay++;
                
            if(ned == needle.size()){
                return start;
            }
            }
             else {
                if (ned > 0) {
                    hay = start + 1; // backtrack
                    ned = 0;
                } else {
                    hay++;
                }
            }
            
        }
        return -1;
    }
};