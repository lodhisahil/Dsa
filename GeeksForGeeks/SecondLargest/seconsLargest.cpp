class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        if(arr.size() < 2){
            return -1;
        }
        int largest = INT_MIN;
        int largestSecond = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > largest){
                largestSecond = largest;
                largest = arr[i];
            } else if(arr[i] > largestSecond && arr[i] != largest){
                largestSecond = arr[i];
            }
            
        }
        if(largestSecond == INT_MIN){
            return -1;
        }
        return largestSecond;
    }
};