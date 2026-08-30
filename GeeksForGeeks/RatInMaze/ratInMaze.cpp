class Solution {
  public:
    void helper(vector<vector<int>>& maze, string& s, vector<string>& ans, int row, int col){
        int n = maze.size();
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        //checking boundary
        if(row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0){
            return;
        }
        
        maze[row][col] = 0;
        
        s.push_back('L');
        helper(maze, s, ans, row, col - 1);//left
        s.pop_back();
        
        s.push_back('R');
        helper(maze, s, ans, row, col + 1);//right
        s.pop_back();
        
        s.push_back('U');
        helper(maze, s, ans, row - 1, col);//up
        s.pop_back();
        
        s.push_back('D');
        helper(maze, s, ans, row + 1, col);//down
        s.pop_back();
        
        maze[row][col] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        string s = "";
        int n = maze.size();
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0){
            return ans;
        }
        helper(maze, s, ans, 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};