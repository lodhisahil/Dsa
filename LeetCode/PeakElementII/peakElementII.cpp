class Solution {
public:
    int findRow(vector<vector<int>>& mat, int mid){
        int n = mat.size();
        int idx = -1;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(mat[i][mid] >= ans){
                ans = mat[i][mid];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int st = 0;
        int end = n-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            int row = findRow(mat, mid);
            int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid+1 < n ? mat[row][mid+1] : -1;
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }else if(mat[row][mid] < left ){
                end = mid - 1;
            }else {
                st = mid + 1;
            }
        }
        return {-1, -1};
    }
};