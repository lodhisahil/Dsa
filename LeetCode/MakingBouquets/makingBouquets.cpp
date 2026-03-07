class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        int boq = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }else {
                boq += (count/k);
                count = 0;
            }
        }
        boq += (count/k);
        if(boq >= m){
            return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long mul = 1LL * m * k;
        if(mul > n) return -1;
        //for finding min and max
        int st = INT_MAX, end = INT_MIN;
        for(int i=0; i<n; i++){
            end = max(end, bloomDay[i]);
            st = min(st, bloomDay[i]);
        }

        while(st <= end){
            int mid = st + (end - st)/2;
            if(possible(bloomDay, mid, m, k)){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return st;
    }
};