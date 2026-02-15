class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> temp;
        if(n == 0){
            return temp;
        }
        int maximum = arr[n-1];
        temp.push_back(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            if(arr[i] >= maximum){
                temp.push_back(arr[i]);
                maximum = arr[i];
            }
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};