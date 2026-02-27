class Solution {
  public:
    int findFloor(vector<int>& arr, int target) {
        // code here
        int st = 0;
        int end = arr.size()-1;
        int ans = -1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(arr[mid] <= target){
                ans = mid;
                st = mid+1;
            } else {
                end = mid-1;
            }
        }
        return ans;
    }
};
