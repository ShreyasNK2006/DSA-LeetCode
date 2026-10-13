/*
 * Problem 1143: Longest Common Subsequence
 * URL     : https://leetcode.com/problems/longest-common-subsequence/
 * Solved  : 2026-09-27
 * Runtime : 26 ms
 * Memory  : 27.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(text1[i]==text2[j])
                {
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[m][n];
    }
};