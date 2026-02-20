class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here

        int xr = 0;
        map<int, int> m;
        m[xr]++;//{0, 1}
        int count = 0;
        for(int i=0; i<arr.size(); i++){
            xr = xr^arr[i];
            //k
            int x = xr^k;
            count +=m[x];
            m[xr]++;
        }
        return count;
    }
};