class Solution {
  public:
  
    bool possible(vector<int> &stalls, int distance, int k){
        int countCows = 1, lastCow = stalls[0];
        for(int i=0; i<stalls.size(); i++){
            if(stalls[i] - lastCow >= distance){
                countCows++;
                lastCow = stalls[i];
            }
        }
        if(countCows >= k){
            return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int st = 1;
        int end = stalls[n-1] - stalls[0];
        
        while(st <= end){
            int mid = st + (end - st)/2;
            if(possible(stalls, mid, k)){
                st = mid + 1;
                
            }else{
                end = mid - 1;
            }
        }
        return end;
    }
};