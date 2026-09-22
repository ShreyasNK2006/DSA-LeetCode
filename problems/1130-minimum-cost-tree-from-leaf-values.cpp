/*
 * Problem 1130: Minimum Cost Tree From Leaf Values
 * URL     : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
 * Solved  : 2026-08-26
 * Runtime : 5 ms
 * Memory  : 13.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> dp;
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        dp.resize(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n-1;i++)
        {
            dp[i][i+1]=arr[i]*arr[i+1];
            dp[i][i]=0;
        }
        dp[n-1][n-1]=0;
        for(int i=n;i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                int cost=INT_MAX;
                int maxl=0;
                vector<int> maxr(j-i,0);
                maxr[j-i-1]=arr[j];
                for(int k=j-1;k>i;k--)
                {
                    maxr[k-i-1]=max(arr[k],maxr[k-i]);
                }
                for(int k=i;k<j;k++)
                {
                    maxl=max(maxl,arr[k]);
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j] +maxl*maxr[k-i]);
                }
            }
        }
        return dp[0][n-1];
    }
};