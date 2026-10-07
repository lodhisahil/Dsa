class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto &p : pairs) {
            unite(p[0], p[1]);
        }
        unordered_map<int, vector<char>> mp;
        for (int i = 0; i < n; i++) {
            mp[find(i)].push_back(s[i]);
        }
        for (auto &it : mp) {
            sort(it.second.begin(), it.second.end());
        }
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            s[i] = mp[root][index[root]];
            index[root]++;
        }
        return s;
    }
};