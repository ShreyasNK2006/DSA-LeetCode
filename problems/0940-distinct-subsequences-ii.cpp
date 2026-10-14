/*
 * Problem 0940: Distinct Subsequences II
 * URL     : https://leetcode.com/problems/distinct-subsequences-ii/
 * Solved  : 2026-09-07
 * Runtime : 0 ms
 * Memory  : 9.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define MOD 1000000007
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> dp(s.size()+1,0);
        dp[0]=1;
        vector<int> last(26,-1);
        for(int i=1;i<=s.size();i++)
        {
            dp[i]=(2*dp[i-1]+MOD)%MOD;
            if(last[s[i-1]-'a']!=-1)
            dp[i]=(dp[i]-dp[last[s[i-1]-'a']]+MOD)%MOD;
            last[s[i-1]-'a']=i-1;
        }
        return (dp[s.size()]-1+MOD)%MOD;
    }
};