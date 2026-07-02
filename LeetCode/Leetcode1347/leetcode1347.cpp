class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(char c : s){
            freq1[c-97]++;
        }
        for(char c : t){
            freq2[c-97]++;
        }
        int steps = 0;
        for(int i=0; i<26; i++){
            steps += abs(freq1[i] - freq2[i]);
        }
        return steps / 2;
    }
};