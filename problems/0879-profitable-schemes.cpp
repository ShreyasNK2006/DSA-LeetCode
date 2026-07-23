/*
 * Problem 0879: Profitable Schemes
 * URL     : https://leetcode.com/problems/profitable-schemes/
 * Solved  : 2026-06-04
 * Runtime : 183 ms
 * Memory  : 56.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define MOD 1000000007
class Solution {
public:
    int findprofit(int i,int j,int k,int &n,int & minProfit,vector<int>& group,vector<int> &profit,vector<vector<vector<int>>> &dp)
    {
        if(i==profit.size())
        {
            if(k>=minProfit && n>=j)
            return 1;
            return 0;
        }
        else if(j>n)
        return 0;
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        int take=0,nottake=0;
        if(j+group[i]<=n)
        take=findprofit(i+1,j+group[i],min(profit[i]+k,minProfit),n,minProfit,group,profit,dp);
        nottake=findprofit(i+1,j,k,n,minProfit,group,profit,dp);
        return dp[i][j][k]=(take+ nottake)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int>(minProfit+1,-1)));

        return findprofit(0,0,0,n,minProfit,group,profit,dp);//ind ,grp,profit
    }
};