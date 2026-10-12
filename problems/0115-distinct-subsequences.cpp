/*
 * Problem 0115: Distinct Subsequences
 * URL     : https://leetcode.com/problems/distinct-subsequences/
 * Solved  : 2026-09-06
 * Runtime : 27 ms
 * Memory  : 44.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        for(int i=0;i<=m;i++)
        dp[i][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};