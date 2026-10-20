/*
 * Problem 2267:  Check if There Is a Valid Parentheses String Path
 * URL     : https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
 * Solved  : 2026-09-29
 * Runtime : 710 ms
 * Memory  : 40.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> open(m, vector<vector<bool>>(n, vector<bool>(m+n, false)));
        open[0][0][1]=true;
        if(grid[0][0]==')' || grid[m-1][n-1]=='(')
        return false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<=m+n-1;k++)
                {
                    if(i>0)
                    {
                        int tp = k;
                        if(grid[i][j]=='(')
                        tp++;
                        else
                        tp--;
                        if(tp>=0 && tp<=m+n-1)
                        open[i][j][tp]=open[i][j][tp]||open[i-1][j][k];
                    }
                    if(j>0)
                    {
                        int tp = k;
                        if(grid[i][j]=='(')
                        tp++;
                        else
                        tp--;
                        if(tp>=0 && tp<=m+n-1)
                        open[i][j][tp]=open[i][j][tp]||open[i][j-1][k];
                    }
                }
            }
        }
        return open[m-1][n-1][0];
    }
};