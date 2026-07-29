/*
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        for (int i = 0; i < ast.size(); i++) {
            if (ast[i] > 0) {
                s.push(ast[i]);
            }else {
                while (!s.empty() && s.top() > 0 && s.top() < -ast[i]) {
                    s.pop();
                }
                if (s.empty() || s.top() < 0) {
                    s.push(ast[i]);
                }else if (s.top() == -ast[i]) {
                    s.pop();
                }
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
*/
//Here we can use a array also in place of a stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> s;
        for(int val: ast){
            if(val > 0){
                s.push_back(val);
            }else{
                while(s.size() > 0 && s.back() > 0 && s.back() < abs(val)){
                    s.pop_back();
                }
                if(s.size() == 0 || s.back() < 0){
                    s.push_back(val);
                }else if(s.back() == abs(val)){
                    s.pop_back();
                }
            }
        }
        return s;
    }
};