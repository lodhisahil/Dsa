class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(operations[i] == "+"){
                ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
            } else if(operations[i] == "D"){
                ans.push_back(ans[ans.size()-1] * 2);
            } else if(operations[i] == "C"){
                ans.pop_back();
            } else {
                ans.push_back(stoi(operations[i]));
            }
        }

        int res = 0;

        for(int i=0; i<ans.size(); i++){
            res += ans[i];
        }

        return res;
    }
};