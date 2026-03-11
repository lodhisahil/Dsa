class Solution {
  public:
    bool possible(vector<int>& arr, int mid, int k){
        int painters = 1, days = 0;
        for(int i=0; i<arr.size(); i++){
            if(days + arr[i] > mid){
                painters++;
                days = arr[i];
            }else{
                days += arr[i];
            }
        }
        if(painters <= k){
            return true;
        }
        return false;
    }
  
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int st = INT_MIN;
        int end = 0;
        for(int i=0; i<n; i++){
            st = max(st, arr[i]);
            end += arr[i];
        }
        
        while(st <= end){
            int mid = st + (end - st)/2;
            if(possible(arr, mid, k)){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return st;
    }
};