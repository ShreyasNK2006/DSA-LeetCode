/*
 * Problem 3989: Maximum Consistent Columns in a Grid
 * URL     : https://leetcode.com/problems/maximum-consistent-columns-in-a-grid/
 * Solved  : 2026-07-12
 * Runtime : 351 ms
 * Memory  : 104.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> comp(n,vector<bool>(n,true));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff=0;
                for(int k=0;k<m;k++)
                {
                    diff=max(diff,abs(grid[k][i]-grid[k][j]));
                }
                if(diff>limit)
                {
                    comp[i][j]=false;
                    comp[j][i]=false;
                }
            }
        }
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(comp[i][j])
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int ans=1;
        for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
        return ans;
    }
};