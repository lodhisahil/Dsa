class Solution {
public:
    bool possible(vector<int>& weights, int val, int days){
        int load = 0;
        int currDays = 1;
        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > val){
                currDays++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        if(currDays <= days){
            return true;
        }
        
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int st = INT_MIN;
        for(int i=0; i<n; i++){
            st = max(st, weights[i]);
        }
        int end = 0;
        for(int i=0; i<n; i++){
            end += weights[i];
        }
        while(st <= end){
            int mid = st + (end - st)/2;
            if(possible(weights, mid, days)){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return st;
    }
};