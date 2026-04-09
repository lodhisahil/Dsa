// User function Template for C++

class Solution {
  public:

    string complement(string bi) {
    int n = bi.length();

    // flip bits
    for(int i = 0; i < n; i++){
        bi[i] = (bi[i] == '1') ? '0' : '1';
    }

    // add 1
    for(int i = n - 1; i >= 0; i--){
        if(bi[i] == '0'){
            bi[i] = '1';
            break;
        } else {
            bi[i] = '0';
        }
    }

    return bi;
}
};