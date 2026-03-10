class Solution {
  public:
  
    bool possible(vector<int> &arr,int mid, int k){
        int pages = 0;
        int students = 1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > mid){
                return false;
            }
            if(pages + arr[i] > mid){
                students++;
                pages = arr[i];
            }else{
                pages += arr[i];
            }
        }
        if(students <= k){
            return true;
        }
        return false;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int ans = -1;
        int n = arr.size();
        if(n < k){
            return -1;
        }
        int st = INT_MIN;
        int end = 0;
        for(int i=0; i<n; i++){
            end += arr[i];
            st = max(st, arr[i]);
        }
        while(st <= end){
            int mid = st + (end - st)/2;
            if(possible(arr, mid, k)){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
};
