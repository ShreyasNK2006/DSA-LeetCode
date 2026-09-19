/*
 * Problem 1000: Minimum Cost to Merge Stones
 * URL     : https://leetcode.com/problems/minimum-cost-to-merge-stones/
 * Solved  : 2026-08-26
 * Runtime : 11 ms
 * Memory  : 13.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> presum;
    int mincost(vector<vector<vector<int>>> &dp,int i,int j,int p,int k)
    {
        if(i==j && p==1)
        return 0;
        if(i==j)
        return INT_MAX/4;
        if(dp[i][j][p]!=-1)
        return dp[i][j][p];
        if(p==1)
        {
            return dp[i][j][p] = mincost(dp,i,j,k,k)+(i==0? presum[j]:presum[j]-presum[i-1]);
        }
        else
        {
            int cost=INT_MAX;
            for(int t=i;t<j;t++)
            {
                cost= min(cost,mincost(dp,i,t,1,k)+mincost(dp,t+1,j,p-1,k));
            }
            return dp[i][j][p]=cost;
        }
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)!=0)
        return -1;
        presum.resize(n,0);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        for(int i=0;i<n;i++)
        {
            presum[i]=stones[i];
            if(i>0)
            presum[i]+=presum[i-1];
        }
        return mincost(dp,0,n-1,1,k);
    }
};