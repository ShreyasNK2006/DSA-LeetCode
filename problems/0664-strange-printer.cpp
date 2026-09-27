/*
 * Problem 0664: Strange Printer
 * URL     : https://leetcode.com/problems/strange-printer/
 * Solved  : 2026-09-03
 * Runtime : 23 ms
 * Memory  : 12.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int strangePrinter(string s) {
        int n =s.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        dp[i][i]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(j==i+1)
                {
                    if(s[i]==s[j])
                    dp[i][j]=1;
                    else
                    dp[i][j]=2;
                    continue;
                }
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                if(s[i]==s[j])
                dp[i][j]--;
            }
        }
        return dp[0][n-1];
    }
};