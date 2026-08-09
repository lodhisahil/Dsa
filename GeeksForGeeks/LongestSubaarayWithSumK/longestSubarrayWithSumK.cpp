class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int length = 0;
        int sum = 0;
        unordered_map<int, int> mapp;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum == k){
                length = max(length, i+1);
            }
            int rem = sum - k;
            if(mapp.find(rem) != mapp.end()){
                length = max(length, i - mapp[rem]);
            }
            if(mapp.find(sum) == mapp.end()){
                mapp[sum] = i;
            }
        }
        return length;
    }
};