/*
 * Problem 0279: Perfect Squares
 * URL     : https://leetcode.com/problems/perfect-squares/
 * Solved  : 2026-06-01
 * Runtime : 42 ms
 * Memory  : 13.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int x=1;x*x<=i;x++)
            {
                dp[i]=min(dp[i],dp[i-x*x]+1);
            }
        }
        return dp[n];
    }
};