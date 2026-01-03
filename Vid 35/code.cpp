#include <iostream>
#include <vector>
using namespace std;

bool linearsearch(int matrix[3][3], int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int maxRowSum(int matrix[][3], int rows, int cols)
{
    int maxSum = 0;
    for (int i = 0; i < rows; i++)
    {
        int rowsumI = 0;
        for (int j = 0; j < cols; j++)
        {
            rowsumI += matrix[i][j];
        }
        maxSum = max(maxSum, rowsumI);
    }
    return maxSum;
}

int maxColsSum(int matrix[][3], int rows, int cols)
{
    int maxSum = 0;
    for (int i = 0; i < cols; i++)
    {
        int colssumI = 0;
        for (int j = 0; j < rows; j++)
        {
            colssumI += matrix[j][i];
        }
        maxSum = max(maxSum, colssumI);
    }
    return maxSum;
}

int diagonalSm(int matrix[][4], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum = sum + matrix[i][j];
            }
            else if (j == n - 1 - i)
            {
                sum = sum + matrix[i][j];
            }
        }
    }
    return sum;
}

int main()
{

    // int matrix[4][4] = {{1, 2, 3,4}, {5, 6,7, 8} ,{ 9,10,11,12},{13,14,15,16}};
    // int n=4;

    vector<vector<int>> matrix = {{1, 2, 3,4}, {5, 6,7, 8} ,{ 9,10,11,12},{13,14,15,16}};
    //rows = matrix.size()
    //cols=1matrix[i].size()

     for(int i=0; i<matrix.size() ; i++){
        for(int j=0; j<matrix[i].size() ;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    // for(int i=0; i<rows ; i++){
    //     for(int j=0; j<cols ;j++){
    //         cin>>matrix[i][j];
    //     }
    // }

    // for(int i=0; i<rows ; i++){
    //     for(int j=0; j<cols ;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}