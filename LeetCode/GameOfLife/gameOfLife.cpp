class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        int n = board.size();
        int m = board[0].size();
        int count = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                count = 0;
                //i --> rows 
                //j --> columns
                //top
                if(i-1 >= 0 && board[i-1][j] == 1)count++;
                //bottom
                if(i+1 < n && board[i+1][j] == 1)count++;
                //left
                if(j-1 >= 0 && board[i][j-1] == 1)count++;
                //right
                if(j+1 < m && board[i][j+1] == 1)count++;
                //top-left
                if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 1)count++;
                //top-right
                if(i-1 >= 0 && j+1 < m && board[i-1][j+1] == 1)count++;
                //bottom-left
                if(i+1 < n && j-1 >= 0 && board[i+1][j-1] == 1)count++;
                //bottom-right
                if(i+1 < n && j+1 < m && board[i+1][j+1] == 1)count++;
                if(count < 2 && board[i][j] == 1){
                    temp[i][j] = 0;
                }else if((count == 2 || count == 3) && board[i][j] == 1){
                    temp[i][j] = 1;
                }else if(count > 3 && board[i][j] == 1){
                    temp[i][j] = 0;
                }else if(count == 3 && board[i][j] == 0){
                    temp[i][j] = 1;
                }
            }
        }
        board = temp;
    }
};