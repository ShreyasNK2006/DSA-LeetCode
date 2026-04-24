/*
 * Problem 0931: Minimum Falling Path Sum
 * URL     : https://leetcode.com/problems/minimum-falling-path-sum/
 * Solved  : 2026-04-06
 * Runtime : 7 ms
 * Memory  : 15 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=matrix[i][j];
                int temp=dp[i-1][j];
                if(j+1<n)
                temp=min(temp,dp[i-1][j+1]);
                if(j-1>=0)
                temp=min(temp,dp[i-1][j-1]);
                dp[i][j]+=temp;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        ans=min(ans,dp[n-1][i]);
        return ans;
    }
};