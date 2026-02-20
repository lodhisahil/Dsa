class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        // NAIVE APPROACH ==>
        // int maxLength = 0;
        // for(int i=0; i<arr.size(); i++){
        //     int sum = 0;
        //     for (int j=i; j<arr.size(); j++){
        //     sum += arr[j];
        //     if(sum == 0){
        //         maxLength = max(maxLength, j-i+1);
        //     }
        //     }
        // }
        // return maxLength;
        
        //OPTIMAL APPROACH ==>
        int n = arr.size();
        int maxLength = 0;
        int sum = 0;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0){
                maxLength = max(maxLength, i+1);
            }else {
                if(m.find(sum) != m.end()){
                maxLength = max(maxLength, i-m[sum]);
            } else {
                m[sum] = i;
            }
            } 
            
        }
        return maxLength;
    }
};