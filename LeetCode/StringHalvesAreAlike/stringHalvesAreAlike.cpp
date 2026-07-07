class Solution {
public:
    bool halvesAreAlike(string s) {
        int i = 0;
        int j = s.length()-1;
        int half = s.length() / 2;
        int count1 = 0;
        int count2 = 0;
        string vovels = "AEIOUaeiou";
        while(i < half && j >= half){
            if(vovels.contains(s[i])){
                count1++;
            }
            if(vovels.contains(s[j])){
                count2++;
            }
            i++;
            j--;
        }
        return count1 == count2;
    }
};