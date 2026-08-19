class Solution {
  public:
    int pageFaults(vector<int>& pages, int c) {
        // code here
        list<int> lru;
        unordered_map<int, list<int>::iterator> mpp;
        int faults = 0;
        for(int page : pages){
            if(mpp.find(page) != mpp.end()){// page hit
                lru.erase(mpp[page]);
            }else{//page fault
                faults++;
                if(lru.size() == c){
                    mpp.erase(lru.back());
                    lru.pop_back();
                }
            }
            lru.push_front(page);
            mpp[page] = lru.begin();
        }
        return faults;
    }
};