class Solution {
public:
    bool isVovel(char c){
        c = tolower(c);
        return(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string reverseVowels(string s) {
        int st = 0;
        int end = s.length() - 1;
        while(st < end){
            while(st < end && !isVovel(s[st])){
                st++;
            }
            while(st < end && !isVovel(s[end])){
                end--;
            }
            swap(s[st], s[end]);
            st++;
            end--;
        }
        return s;
    }
};