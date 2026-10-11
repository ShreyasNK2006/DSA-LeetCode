/*
 * Problem 0052: N-Queens II
 * URL     : https://leetcode.com/problems/n-queens-ii/
 * Solved  : 2026-07-22
 * Runtime : 0 ms
 * Memory  : 8.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> col;
    vector<vector<int>> grid;
    void simulate(int &n,int &c,int r)
    {
        if(r==n)
        {
            c++;
            return;
        }
        for(int i=0;i<n;i++)
        {
            bool cond=true;
            if(col[i]==0)
            {
                for(int j=i-1;j>=0 && (r-(i-j))>=0;j--)
                {
                    if(grid[r-(i-j)][j]==1)
                    {
                        cond=false;
                        break;
                    }
                }
                for(int j=i+1;j<n && r-(j-i)>=0;j++)
                {
                    if(grid[r-(j-i)][j]==1)
                    {
                        cond=false;
                        break;
                    }
                }
                if(cond)
                {
                    grid[r][i]=1;
                    col[i]=1;
                    simulate(n,c,r+1);
                }
                grid[r][i]=0;
                col[i]=0;
            }
        }
    }
    int totalNQueens(int n) {
        int c=0;
        col.resize(n);
        grid.resize(n,vector<int>(n,0));
        simulate(n,c,0);
        return c;
    }
};