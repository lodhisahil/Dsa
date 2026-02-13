class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long expected = (n+1)*(n+2)/2;
        long long actual = accumulate(arr.begin(), arr.end(), 0);
        return expected - actual;
    }
};