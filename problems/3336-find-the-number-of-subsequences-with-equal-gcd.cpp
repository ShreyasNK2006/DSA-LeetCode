/*
 * Problem 3336: Find the Number of Subsequences With Equal GCD
 * URL     : https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/
 * Solved  : 2026-07-15
 * Runtime : 314 ms
 * Memory  : 292.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define mod 1000000007
int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int maxn = 1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        maxn=max(maxn,nums[i]);
        vector<vector<int>> dp(maxn+1,vector<int>(maxn+1,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> dp2(maxn+1,vector<int>(maxn+1,0));
            for(int j=0;j<=maxn;j++)
            {
                int j1= gcd(j,nums[i]);
                for(int k=0;k<=maxn;k++)
                {
                    if(dp[j][k]==0)
                    continue;
                    int k1=gcd(k,nums[i]);
                    dp2[j1][k]=(dp2[j1][k]+dp[j][k])%mod;
                    dp2[j][k1]=(dp2[j][k1]+dp[j][k])%mod;
                    dp2[j][k]=(dp2[j][k]+dp[j][k])%mod; 
                }
            }
            dp=dp2;
        }
        int sum=0;
        for(int j=1;j<=maxn;j++)
        sum=(sum+dp[j][j])%mod;
        return sum;
    }
};