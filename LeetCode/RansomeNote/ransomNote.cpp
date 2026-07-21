class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for(int i=0; i<magazine.length(); i++){
            freq[magazine[i] - 97]++;
        }
        for(int i=0; i<ransomNote.length(); i++){
            if(freq[ransomNote[i] - 97] <= 0){
                return false;
            }else{
                freq[ransomNote[i] - 97]--;
            }
        }
        return true;
    }
};