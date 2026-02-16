class Solution {
public:
    //MY APPROACH-->
    // void helper(vector<vector<int>>& matrix, int row, int col){
    //     //set whole row to 0
    //     for(int i=0; i<matrix[0].size(); i++){
    //         matrix[row][i] = 0;
    //     }
    //     //set whole column to 0
    //     for(int i=0; i<matrix.size(); i++){
    //         matrix[i][col] = 0;
    //     }
    // }
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<pair<int,int>> v;
    //     for(int i=0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //             if(matrix[i][j] == 0){
    //                 v.push_back({i, j});
    //             }
    //         }
    //     }
    //     int vSz = v.size();
    //     while(v.size() > 0){
    //         helper(matrix, v.back().first, v.back().second);
    //         v.pop_back();
    //     }

    //optimal approach
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0){
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                    
                }
            }
        }


        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};