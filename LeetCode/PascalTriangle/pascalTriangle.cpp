class Solution {
public:
    vector<int> helper(int N){
        vector<int> ansRow;
        int ans = 1;
        ansRow.push_back(1);
        for(int i=1; i<N; i++){
            ans = ans*(N-i);
            ans = ans/i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int N) {
        vector<vector<int>> answer;
        for(int i=1; i<=N; i++){
            answer.push_back(helper(i));
        }
        return answer;
    }
};