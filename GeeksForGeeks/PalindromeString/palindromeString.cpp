class Solution {
  public:
    bool helper(string &s, int n, int i){
        if(i >= n/2){
            return true;
        }
        if(s[i] != s[n-i-1]){
            return false;
        }
        helper(s, n, i+1);
    }
    bool isPalindrome(string& s) {
        // code here
        return helper(s, s.length(), 0);
    }
};