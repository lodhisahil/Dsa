class Solution {
public:
    string sortVowels(string s) {
        int cnt[128] = {0};
        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'|| c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
        };
        for (char c : s)
            if (isVowel(c)) cnt[(int)c]++;
        const char order[] = {'A','E','I','O','U','a','e','i','o','u'};
        int p = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                while (cnt[(int)order[p]] == 0) p++;
                c = order[p];
                cnt[(int)order[p]]--;
            }
        }
        return s;
    }
};