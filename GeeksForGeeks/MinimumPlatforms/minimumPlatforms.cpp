class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int count = 0;
        int ans = 0;
        int r = 0;
        int l = 0;
        while(r < arr.size()){
            if(arr[r] <= dep[l]){
                count++;
                r++;
            }else{
                count--;
                l++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
