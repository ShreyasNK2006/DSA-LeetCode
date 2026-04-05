/*
 * Problem 1312: Minimum Insertion Steps to Make a String Palindrome
 * URL     : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 * Solved  : 2026-03-18
 * Runtime : 32 ms
 * Memory  : 31.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minInsertions(string s) {
        string s2=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(s[i]==s2[j])
                dp[i][j]=1+dp[i+1][j+1];
                else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return n-dp[0][0];
    }
};