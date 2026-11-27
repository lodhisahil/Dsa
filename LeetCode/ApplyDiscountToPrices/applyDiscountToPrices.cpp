class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word, result;
        bool first = true;
        while (ss >> word) {
            if (!first) result += ' ';
            first = false;
            if (isPrice(word)) {
                long long price = stoll(word.substr(1));
                double newPrice = price * (100 - discount) / 100.0;
                char buf[32];
                snprintf(buf, sizeof(buf), "$%.2f", newPrice);
                result += buf;
            } else {
                result += word;
            }
        }
        return result;
    }
private:
    bool isPrice(const string& w) {
        if (w.size() < 2 || w[0] != '$') return false;
        for (int i = 1; i < (int)w.size(); i++) {
            if (!isdigit(w[i])) return false;
        }
        return true;
    }
};