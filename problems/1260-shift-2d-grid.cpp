/*
 * Problem 1260: Shift 2D Grid
 * URL     : https://leetcode.com/problems/shift-2d-grid/
 * Solved  : 2026-07-20
 * Runtime : 3 ms
 * Memory  : 18.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size(),n=grid[0].size();
        vector<vector<int>> temp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int xs=(i+k/(n)+(j+k%n)/n)%m;
                int ys=(j+k%n)%n;
                temp[xs][ys]=grid[i][j];
            }
        }
    return temp;
    }
};