class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int maxDefense = 0;
        int weak = 0;
        for (auto& p : properties) {
            if (p[1] < maxDefense) weak++;
            else maxDefense = p[1];
        }
        return weak;
    }
};