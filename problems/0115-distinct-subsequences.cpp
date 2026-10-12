/*
 * Problem 0115: Distinct Subsequences
 * URL     : https://leetcode.com/problems/distinct-subsequences/
 * Solved  : 2026-09-06
 * Runtime : 26 ms
 * Memory  : 26.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(m+1,0));
        for(int i=0;i<=n;i++)
        dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};