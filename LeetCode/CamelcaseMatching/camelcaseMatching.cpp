class Solution {
public:
    bool check(string query, string pattern) {
        int j = 0;
        for (char ch : query) {
            if (j < pattern.size() && ch == pattern[j]) {
                j++;
            }
            else if (isupper(ch)) {
                return false;
            }
        }
        return j == pattern.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        for (string query : queries) {
            answer.push_back(check(query, pattern));
        }
        return answer;
    }
};