# Pascal's Triangle
Solved on 2025-07-25

class Solution {
public:
    int fact(int row,int col)
    {
        int res=1;
        for(int i =1;i<=col;i++)
        {
            res*=(row-col+i);
            res/=i;
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix(numRows);
        for(int i =0;i<numRows;i++)
        {
            for(int j =0;j<=i;j++)
            {
               matrix[i].insert(matrix[i].begin()+j,fact(i,j));
            }
        }
        return matrix;
    }
};