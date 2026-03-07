class Solution {
public:
    int maxi(vector<int>& piles){
        int ans = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            ans = max(ans, piles[i]);
        }
        return ans;
    }

    long long totalHours(vector<int>& piles, int perHour){
        int n = piles.size();
        long long totalHours = 0;
        for(int i=0; i<n; i++){
            totalHours += ((long long)piles[i] + perHour - 1) / perHour;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //binary search
        int st = 1;
        int end = maxi(piles);
        while(st <= end){
            int mid = st + (end - st)/2;
            long long totalHrs = totalHours(piles, mid);
            if(totalHrs <= h){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        } 
        return st;
    }
};