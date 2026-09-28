class Solution {
public:
    bool solve(string& num, int idx, vector<int>& ans){
        if(idx == num.size()){
            return ans.size() >= 3;
        }
        long long val = 0;
        for(int i = idx; i < num.size(); i++){
            if(i > idx && num[idx] == '0'){
                break;
            }
            val = val * 10 + (num[i] - '0');
            if(val > INT_MAX){
                break;
            }
            int n = ans.size();
            if(n >= 2){
                long long sum = (long long)ans[n - 1] + ans[n - 2];
                if(val < sum){
                    continue;
                }
                if(val > sum){
                    break;
                }
            }
            ans.push_back(val);
            if(solve(num, i + 1, ans)){
                return true;
            }
            ans.pop_back();
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        solve(num, 0, ans);
        return ans;
    }
};