/*
 * Problem 0091: Decode Ways
 * URL     : https://leetcode.com/problems/decode-ways/
 * Solved  : 2026-05-16
 * Runtime : 0 ms
 * Memory  : 8.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='0')
            {
                dp[i]=dp[i+1];
                if(i<n-1)
                {
                    if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
                    dp[i]=dp[i]+dp[i+2];
                }
            }
        }
        return dp[0];
    }
};