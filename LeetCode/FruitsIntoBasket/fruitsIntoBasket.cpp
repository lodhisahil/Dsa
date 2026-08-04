class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int maxLength = 0;
        unordered_map<int, int> mpp;
        while(r < n){
            if(mpp.size() == 2 && mpp.find(fruits[r]) == mpp.end()){//new element h purane ko hatao ;
            int idx = INT_MAX;
            int key;
            for(auto itr : mpp){
                if(itr.second < idx){
                    idx = itr.second;
                    key = itr.first;
                }
            }
                mpp.erase(key);
                l = idx + 1;
            }
            mpp[fruits[r]] = r;
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};