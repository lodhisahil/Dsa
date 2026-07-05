class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> freq(26,false);
        int count = 0;
        for(int i=0; i<sentence.length(); i++){
            if(freq[sentence[i] - 97] == false){
                freq[sentence[i] - 97] = true;
                count++;
            }
            if(count == 26){
                return true;
            }
        }
        return false;
    }
};