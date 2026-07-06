class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        int j = 0;
        string ans = "";
        while(i < s.length()){
            if(j < spaces.size() && i == spaces[j]){
                ans += ' ';
                ans += s[i];
                j++;
            }else{
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};