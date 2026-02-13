class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        int m = b.size();
        vector<int> temp;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] <= b[j]){
                if(temp.size() == 0 || temp.back() != a[i]){
                    temp.push_back(a[i]);
                }
                i++;
            }else{
                if(temp.size() == 0 || temp.back() != b[j]){
                    temp.push_back(b[j]);
                }
                j++;
            }
        }
        while(i < n){
            if(temp.size() == 0 || temp.back() != a[i]){
                temp.push_back(a[i]);
            }
            i++;
        }
        while(j < m){
            if(temp.size() == 0 || temp.back() != b[j]){
                temp.push_back(b[j]);
            }
            j++;
        }
        return temp;
    }
};