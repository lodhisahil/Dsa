class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int largest = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            largest = max(largest, arr[i]);
        }
        return largest;
    }
};
