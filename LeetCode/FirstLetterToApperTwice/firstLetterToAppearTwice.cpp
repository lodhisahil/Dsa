class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> st;
        char ans;
        for(char c : s){
            if(st.find(c) != st.end()){
                ans = c;
                break;
            }else{
                st.insert(c);
            }
        }
        return ans;
    }
};