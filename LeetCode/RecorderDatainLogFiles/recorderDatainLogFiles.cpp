class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<tuple<string, string, string>> letters;
        vector<string> digits;
        for (auto& log : logs) {
            int sp = log.find(' ');
            string id = log.substr(0, sp);
            string content = log.substr(sp + 1);
            if (isdigit(content[0])) {
                digits.push_back(log);
            } else {
                letters.emplace_back(content, id, log);
            }
        }
        sort(letters.begin(), letters.end());
        vector<string> res;
        for (auto& [c, i, log] : letters) res.push_back(log);
        for (auto& d : digits) res.push_back(d);
        return res;
    }
};