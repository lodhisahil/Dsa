class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        int mutations = 0;
        string chars = "ACGT";
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();
                if (curr == endGene) {
                    return mutations;
                }
                for (int i = 0; i < curr.length(); i++) {
                    char original = curr[i];
                    for (char ch : chars) {
                        if (ch == original) {
                            continue;
                        }
                        curr[i] = ch;
                        if (valid.count(curr) && !visited.count(curr)) {
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = original;
                }
            }
            mutations++;
        }
        return -1;
    }
};