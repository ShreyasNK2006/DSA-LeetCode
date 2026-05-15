/*
 * Problem 1914: Cyclically Rotating a Grid
 * URL     : https://leetcode.com/problems/cyclically-rotating-a-grid/
 * Solved  : 2026-05-09
 * Runtime : 21 ms
 * Memory  : 20.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        for(int l=1;l<=min(m/2,n/2);l++)
        {
            vector<int> temp,r,c;
            for(int j=l-1;j<=m-l;j++)
            {
                temp.push_back(grid[j][l-1]);
                r.push_back(j);
                c.push_back(l-1);
            }
            for(int j=l;j<n-l;j++)
            {
                temp.push_back(grid[m-l][j]);
                r.push_back(m-l);
                c.push_back(j);
            }
            for(int j=m-l;j>=l-1;j--)
            {
                temp.push_back(grid[j][n-l]);
                r.push_back(j);
                c.push_back(n-l);
            }
            for(int j=n-1-l;j>l-1;j--)
            {
                temp.push_back(grid[l-1][j]);
                r.push_back(l-1);
                c.push_back(j);
            }
            int sz=temp.size();
            int shft=k%sz;
            for(int i=0;i<sz;i++)
            {
                int idx=(i+sz-shft)%sz;
                grid[r[i]][c[i]]=temp[idx];
            }
        }
        return grid;
    }
};