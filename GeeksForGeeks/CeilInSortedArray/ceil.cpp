// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int st = 0; 
        int end = arr.size()-1;
        int ans = -1;
        
        while(st <= end){
            int mid = st + (end-st)/2;
            if(arr[mid] >= x){
                ans = mid;
                end = mid-1;
            } else {
                st = mid+1;
            }
        }
        return ans;
    }
};