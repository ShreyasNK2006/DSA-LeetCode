/*
 * Problem 1594: Maximum Non Negative Product in a Matrix
 * URL     : https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
 * Solved  : 2026-03-23
 * Runtime : 3 ms
 * Memory  : 14.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define MOD 1000000007
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<long long>>>dp(2,vector<vector<long long>>(m,vector<long long>(n,1)));
        for(int i=0;i<m;i++)
        {
            if(i>0)
            {
                dp[0][i][0]=dp[0][i-1][0];
            }
            dp[0][i][0]=(dp[0][i][0]*grid[i][0])%MOD;
            dp[1][i][0]=dp[0][i][0];
        }
        for(int j=1;j<n;j++)
        {
            dp[1][0][j]=dp[1][0][j-1];
            dp[1][0][j]=(dp[1][0][j]*grid[0][j])%MOD;
            dp[0][0][j]=dp[1][0][j];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(grid[i][j]<0)
                {
                    dp[1][i][j]=(grid[i][j]*min(dp[0][i-1][j],dp[0][i][j-1]));
                    dp[0][i][j]=(grid[i][j]*max(dp[1][i-1][j],dp[1][i][j-1]));
                }
                else
                {
                    dp[1][i][j]=(grid[i][j]*max(dp[1][i-1][j],dp[1][i][j-1]));
                    dp[0][i][j]=(grid[i][j]*min(dp[0][i-1][j],dp[0][i][j-1]));
                }
            }
        }
        return dp[1][m-1][n-1]>=0?dp[1][m-1][n-1]%MOD:-1;
    }
};