class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int end=0; end<word.length(); end++){
            if(word[end] == ch){
                int st = 0;
                while(st < end){
                    swap(word[st], word[end]);
                    st++;
                    end--;
                }
                return word;
            }
        }
        return word;
    }
};