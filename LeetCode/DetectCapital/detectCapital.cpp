class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(char c : word){
            if(c >= 65 && c <= 90){
                count++;
            }
        }
        if((count == 1 && (word[0] >= 65 && word[0] <= 90)) || count == 0 || count == word.length()){
            return true;
        }
        return false;
    }
};