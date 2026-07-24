/*
 * Problem 0892: Surface Area of 3D Shapes
 * URL     : https://leetcode.com/problems/surface-area-of-3d-shapes/
 * Solved  : 2026-07-02
 * Runtime : 0 ms
 * Memory  : 13 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int a=0;
        for(int i=0;i<grid[0].size();i++)
            {
                a=a+grid[0][i];
            }
        for(int i=0;i<grid[0].size();i++)
            {
                a=a+grid[grid.size()-1][i];
            }
        for(int i=0;i<grid.size();i++)
            {
                a=a+grid[i][0];
            }
        for(int i=0;i<grid.size();i++)
            {
                a=a+grid[i][grid[0].size()-1];
            }
        for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                    {
                        if(grid[i][j]!=0)
                            a+=2;
                        if(j==grid[0].size()-1)
                        {
                            if(i<grid.size()-1)
                            {
                                a=a+abs(grid[i][j]-grid[i+1][j]);
                            }
                        }
                        else
                        {
                            if(i<grid.size()-1)
                            {
                                a=a+abs(grid[i][j]-grid[i+1][j]);
                            }
                            a=a+abs(grid[i][j]-grid[i][j+1]);
                        }
                    }
            }
        return a;
    }
};