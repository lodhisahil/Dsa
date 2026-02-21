class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long sum = 0;
        long long squareSum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            squareSum += (long long)arr[i] * (long long)arr[i];
        }
        //missing = x
        //repeating = y 
        long long sumExp = (n * (n+1))/2;
        long long squareSumExp = ( n * (n+1) * (2*n+1) )/ 6;
        long long val1 = sum - sumExp;                         //x-y
        long long val2 = squareSum - squareSumExp;            //x2-y2 = (x+y)(x-y)
        val2 = val2 / val1;                                  //x+y
        long long x = (val1 + val2)/2; 
        long long y = val2 -  x;
        return {(int)x, (int)y};
    }
};
