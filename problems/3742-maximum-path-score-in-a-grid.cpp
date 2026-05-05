/*
 * Problem 3742: Maximum Path Score in a Grid
 * URL     : https://leetcode.com/problems/maximum-path-score-in-a-grid/
 * Solved  : 2026-04-30
 * Runtime : 928 ms
 * Memory  : 499.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
  
        int m=grid. size(),n=grid[0]. size();
        vector<vector<vector<int>>> score(m,vector<vector<int>>(n,vector<int>(k+1,INT_MIN)));
       int l=grid[0][0]==0?0:1;
       if(l>k)
       return -1;
        score[0][0][l]=grid[0][0];
           for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&& j==0)
                continue;
                int s=grid[i][j],c=0;
                if(grid[i][j]!=0)
                c=1;
                if(j>0)
                {
                   for(int o=0;c+o<=k;o++)
                   {
                       if(score[i][j-1][o]!=INT_MIN)
                       score[i][j][o+c]=s+score[i][j-1][o];
                   }
                }
                if(i>0)
                {
                    for(int o=0;c+o<=k;o++)
                   {
                       if( score[i-1][j][o]!=INT_MIN)
                       score[i][j][o+c]=max(score [i][j][o+c],s+score[i-1][j][o]);
                   }
                }
            }
        }
        int maxscore=-1;
        for(int o=0;o<=k;o++)
        maxscore=max(maxscore, score [m-1][n-1][o]);
        return maxscore;
    }
};