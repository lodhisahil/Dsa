class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<int> box(n+1, 1);
        box[0] = box[1] = 0;
        for(int i=2; i*i <= n; i++){
            if(box[i] == 1){
                for(int j=i*i; j<=n; j+=i){
                    box[j] = 0;
                }
            }
        }
        vector<int> ans;
        for(int i=2; i<=n; i++){
            if(box[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};