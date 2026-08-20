class Solution {
  public:
  
    void rev(vector<int> &arr, int st, int end){
        if(st >= end){
            return;
        }
        swap(arr[st], arr[end]);
        rev(arr, st+1, end-1);
    }
  
    void reverseArray(vector<int> &arr) {
        // code here
        rev(arr, 0, arr.size()-1);
    }
};