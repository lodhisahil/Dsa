class Solution {
public:
    void helper(vector<vector<char>>& board, string word, int idx, bool& ans, int row, int col){
        int n = word.length();
        //base case h ye
        if(idx == n){
            ans = true;
            return;
        }
        // Boundary check
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
            return;
        }
        //check if match or not
        if(board[row][col] != word[idx]){
            return;
        }
        //mil gya h - to ab usko mark kardege aur temp me purana char store karlege 
        char temp = board[row][col];
        board[row][col] = '#';

        //check all 4 directions of the board
        helper(board, word, idx + 1, ans, row, col + 1);//aage
        if(ans) return;
        helper(board, word, idx + 1, ans, row, col - 1);//pichhe
        if(ans) return;
        helper(board, word, idx + 1, ans, row + 1, col);//niche
        if(ans) return;
        helper(board, word, idx + 1, ans, row - 1, col);//upar

        //backtrack
        board[row][col] = temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool ans = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    helper(board, word, 0, ans, i, j);
                }
            }
        }
        return ans;        
    }
};