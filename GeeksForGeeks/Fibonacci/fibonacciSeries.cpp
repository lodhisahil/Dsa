class Solution {
  public:
    int fibb(int n){
        if( n <= 1){
            return n;
        }
        return fibb(n-1) + fibb(n-2);
    }
    int nthFibonacci(int n) {
        // code here
        return fibb(n);
    }
};