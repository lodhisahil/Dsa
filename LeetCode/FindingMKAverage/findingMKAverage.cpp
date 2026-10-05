class MKAverage {
private:
    int m, k;
    queue<int> q;
    multiset<int> small;
    multiset<int> middle;
    multiset<int> large;
    long long middleSum = 0;
    void add(int x) {
        if (small.empty() || x <= *small.rbegin()) {
            small.insert(x);
        }
        else if (large.empty() || x >= *large.begin()) {
            large.insert(x);
        }
        else {
            middle.insert(x);
            middleSum += x;
        }
        balance();
    }
    void remove(int x) {
        auto it = small.find(x);
        if (it != small.end()) {
            small.erase(it);
        }
        else {
            it = middle.find(x);
            if (it != middle.end()) {
                middle.erase(it);
                middleSum -= x;
            }
            else {
                it = large.find(x);
                large.erase(it);
            }
        }
        balance();
    }
    void balance() {
        // small should contain exactly k elements
        while (small.size() > k) {
            auto it = prev(small.end());
            int x = *it;
            small.erase(it);
            middle.insert(x);
            middleSum += x;
        }
        while (small.size() < k && !middle.empty()) {
            auto it = middle.begin();
            int x = *it;
            middle.erase(it);
            middleSum -= x;
            small.insert(x);
        }
        // large should contain exactly k elements
        while (large.size() > k) {
            auto it = large.begin();
            int x = *it;
            large.erase(it);
            middle.insert(x);
            middleSum += x;
        }
        while (large.size() < k && !middle.empty()) {
            auto it = prev(middle.end());
            int x = *it;
            middle.erase(it);
            middleSum -= x;
            large.insert(x);
        }
    }
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    void addElement(int num) {
        q.push(num);
        add(num);
        if (q.size() > m) {
            int old = q.front();
            q.pop();
            remove(old);
        }
    }
    int calculateMKAverage() {
        if (q.size() < m) {
            return -1;
        }
        return middleSum / (m - 2 * k);
    }
};