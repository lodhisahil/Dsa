class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int idx = -1;
        int max1 = 0;
        for(int i=0; i<n; i++){
            int st = 0;
            int end = m-1;
            while(st <= end){
                int mid = st + (end - st)/2;
                if(arr[i][mid] == 1){
                    end = mid - 1;
                }else{
                    st = mid + 1;
                }
            }
            if(max1 < m-st){
                max1 = m-st;
                idx = i;
            }
        }
        return idx;
    }
};