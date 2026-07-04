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