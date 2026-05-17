class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> list;
        for(int i=2; i*i <= n; i++){
            if(n%i == 0){
                list.push_back(i);
                while(n%i == 0){
                    n = n/i;
                }
            }
        }
        if(n != 1){
            list.push_back(n);
        }
        return list;
    }
};