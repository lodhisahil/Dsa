class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l = 0;
        int r = 0;
        int length = -1;
        unordered_map<char, int> m;
        while(r < s.length()){
            m[s[r]] = r;
            while(m.size() > k){
                int idx = INT_MAX;
                int val;
                for(auto itr : m){
                    if(itr.second < idx){
                        idx = itr.second;
                        val = itr.first;
                    }
                }
                l = idx + 1;
                m.erase(val);
            }
            if(m.size() == k){
                length = max(length, r - l + 1);
            }
            r++;
        }
        return length;
    }
};