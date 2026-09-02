/*
 * Problem 1510: Stone Game IV
 * URL     : https://leetcode.com/problems/stone-game-iv/
 * Solved  : 2026-08-11
 * Runtime : 15 ms
 * Memory  : 11.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i*i<=n;i++)
        {
            dp[i*i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            if(dp[i])
            continue;
            for(int j=1;j*j<=i;j++)
            {
                if(dp[i-j*j]==0)
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n]==1;
    }
};