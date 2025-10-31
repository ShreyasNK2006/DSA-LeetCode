# N-Queens
Solved on 2025-10-08

class Solution {
public:
    void solve(int col,vector<string>& temp, vector<vector<string>>& res,vector<int> leftrow,vector<int> upperdiagonal,vector<int> lowerdiagonal,int n)
    {
        if(col==n)
        {
            res.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(lowerdiagonal[row+col]==0 && upperdiagonal[n-1 + col -row]==0 && leftrow[row]==0)
            {
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+col-row]=1;
                leftrow[row]=1;
                temp[row][col]='Q';
                solve(col+1,temp,res,leftrow,upperdiagonal,lowerdiagonal,n);
                temp[row][col]='.';
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+col-row]=0;
                leftrow[row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> upperdiagonal(2*n-1,0), lowerdiagonal(2*n-1,0),leftrow(n,0);
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        temp[i]=s;
        solve(0,temp,res,leftrow,upperdiagonal,lowerdiagonal,n);
        return res;

    }
};