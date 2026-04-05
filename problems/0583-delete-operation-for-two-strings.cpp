/*
 * Problem 0583: Delete Operation for Two Strings
 * URL     : https://leetcode.com/problems/delete-operation-for-two-strings/
 * Solved  : 2026-03-18
 * Runtime : 13 ms
 * Memory  : 16.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(word1[i]==word2[j])
                dp[i][j]=1+dp[i+1][j+1];
                else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return m+n-2*dp[0][0];
    }
};