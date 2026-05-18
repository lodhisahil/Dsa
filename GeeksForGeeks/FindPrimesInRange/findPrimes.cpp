// User function Template for C++

class Solution {
  public:
    bool isPrime(int num){
        if(num <= 1)return false;
        for(int i=2; i*i <= num; i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    vector<int> primeRange(int M, int N) {
        // code here
        vector<int> ans;
        for(int i=M; i<=N; i++){
            if(isPrime(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};