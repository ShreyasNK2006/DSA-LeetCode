/*
 * Problem 1140: Stone Game II
 * URL     : https://leetcode.com/problems/stone-game-ii/
 * Solved  : 2026-08-11
 * Runtime : 15 ms
 * Memory  : 13.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int m,vector<int>&piles)
    {
        if(i>=piles.size())
        return 0;
        if(dp[i][m]!=-1)
        return dp[i][m];
        int ans =INT_MIN;
        int total = 0;
        for(int j=1;j<=2*m;j++)
        {
            if(j+i-1<piles.size())
            total+=piles[j+i-1];
            ans= max(ans,total - dfs(i+j,max(m,j),piles));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n,vector<int>(n+1,-1));
        int a= dfs(0,1,piles);
        int sum=0;
        for(auto x:piles)
        sum+=x;
        return (sum+a)/2;
    }
};