class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int st = 0;
        int end = arr.size()-1;
        int ans = arr.size();
        
        while(st <= end){
            int mid = st + (end-st)/2;
            if(arr[mid] >= target){
                ans = mid;
                end = mid-1;
            } else {
                st = mid+1;
            }
        }
        return ans;
    }
};
