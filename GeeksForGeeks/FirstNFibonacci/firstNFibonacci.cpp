// User function template for C++

class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int> ans;
        if(n >= 1){
            ans.push_back(0);
        }
        if(n >= 2){
            ans.push_back(1);
        }
        for(int i=2; i<n; i++){
            ans.push_back(ans[i-1] + ans[i-2]);
        }
        return ans;
    }
};