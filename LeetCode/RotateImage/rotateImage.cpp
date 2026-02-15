class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //My approach
        // int n = matrix.size();
        // vector<vector<int>> temp = matrix;
        // int row = 0;
        // for(int i = n-1; i>=0; i--){// for traversing the rightmost column of matrix
        //     int col = 0;
        //     for(int j=0; j<n; j++){//for traversing whole row
        //         matrix[j][i] = temp[row][col];
        //         col++;
        //     }
        //     row++;
        // }

        // Optimal approach
        int n = matrix.size();
        //transpose the matrix
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse every row
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};