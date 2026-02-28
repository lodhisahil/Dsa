class Solution {
  public:
  
    int findFirst(vector<int>& arr, int target){
        int n = arr.size();
        int st = 0;
        int end = n-1;
        int ans = -1;
        while( st <= end ){
            int mid = st + (end-st)/2;
            if(arr[mid] == target){
                ans = mid;
                end = mid-1;
            } else if(arr[mid] > target){
                end = mid-1;
            } else {
                st = mid+1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& arr, int target){
        int n = arr.size();
        int st = 0;
        int end = n-1;
        int ans = -1;
        while( st <= end ){
            int mid = st + (end-st)/2;
            if(arr[mid] == target){
                ans = mid;
                st = mid+1;
            } else if(arr[mid] > target){
                end = mid-1;
            } else {
                st = mid+1;
            }
        }
        return ans;
    }
  
    int countFreq(vector<int>& arr, int target) {
        // code here
        if(findLast(arr, target) == -1 && findFirst(arr, target) == -1){
            return 0;
        }
        return(findLast(arr, target) - findFirst(arr, target) + 1);
    }
};