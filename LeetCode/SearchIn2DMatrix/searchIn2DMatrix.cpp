class Solution {
public:
    bool searchInRow(vector<int> &arr, int target){
        int n = arr.size();
        int st = 0;
        int end = n-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid] < target){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int st = 0;
        int end = n-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(matrix[mid][0] <= target && matrix[mid][m-1] >= target){
                return searchInRow(matrix[mid], target);
            }else if(matrix[mid][0] > target){
                end = mid - 1;
            }else {
                st = mid + 1;
            }
        }
        return false;
    }
};