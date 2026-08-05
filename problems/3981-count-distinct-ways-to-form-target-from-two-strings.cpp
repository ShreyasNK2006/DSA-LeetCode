/*
 * Problem 3981: Count Distinct Ways to Form Target from Two Strings
 * URL     : https://leetcode.com/problems/count-distinct-ways-to-form-target-from-two-strings/
 * Solved  : 2026-07-11
 * Runtime : 1183 ms
 * Memory  : 49.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define mod 1000000007
class Solution {
public:
    int dfs(vector<vector<vector<int>>> &dp,int i,int j,int k,string &a,string &b,string &c)
    {
        if(k==c.size())
        return i&&j;
        if(i==a.size()&& j==b.size())
        return 0;
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        long long ans=0;
        for(int t=i;t<a.size();t++)
        {
            if(c[k]==a[t])
            {
                ans=(ans+dfs(dp,t+1,j,k+1,a,b,c))%mod;
            }
        }
        for(int t=j;t<b.size();t++)
        {
            if(c[k]==b[t])
            {
                ans=(ans+dfs(dp,i,t+1,k+1,a,b,c))%mod;
            }
        }
        return dp[i][j][k]=ans;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        int n1=word1.size();
        int n2=word2.size();
        int m=target.size();
        vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(m,-1)));
        return dfs(dp,0,0,0,word1,word2,target);
    }
};