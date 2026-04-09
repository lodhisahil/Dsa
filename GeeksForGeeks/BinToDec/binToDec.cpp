class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int ans = 0;
        int n = b.length();
        for(int i=n-1; i>=0; i--){
            if(b[i] == '1'){
                ans += pow(2, (n - i - 1));
            }
        }
        return ans;
    }
};