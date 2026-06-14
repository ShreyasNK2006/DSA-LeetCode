/*
 * Problem 3946: Maximum Number of Items From Sale I
 * URL     : https://leetcode.com/problems/maximum-number-of-items-from-sale-i/
 * Solved  : 2026-05-31
 * Runtime : 223 ms
 * Memory  : 133.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    /*void findcomb(vector<vector<int>>& items, int budget,vector<int>& ic,int n, int ind,int &maxc,int c,vector<bool> selected)
    {
        if(ind==n ||budget==0)
            return;
        if(budget>=items[ind][1])
        {
            if(!selected[ind])
            {
                selected[ind]=true;
                maxc=max(maxc,c+ic[ind]);
                findcomb(items,budget-items[ind][1],ic,n,ind,maxc,c+ic[ind],selected);
            }
            else
            {
                maxc=max(maxc,c+1);
                findcomb(items,budget-items[ind][1],ic,n,ind,maxc,c+1,selected);
            }
        }
        findcomb(items,budget,ic,n,ind+1,maxc,c,selected);
    }*/
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int minc=INT_MAX;
        vector<int> ic(n,0);
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if(items[j][0]%items[i][0]==0)
                            ic[i]++;
                    }
                minc=min(minc,items[i][1]);
            }
        vector<vector<int>> dp(n+1,vector<int>(budget+1,0));
        for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=budget;j++)
                    {
                        if(j>=items[i-1][1])
                        {
                            dp[i][j]=max(dp[i-1][j],ic[i-1]+dp[i-1][j-items[i-1][1]]);
                        }
                        else
                            dp[i][j]=dp[i-1][j];
                    }
            }
        int maxc=0;
        for(int i=1;i<=budget;i++)
            {
                int rem=budget-i;
                maxc=max(maxc,dp[n][i]+(rem/minc));
            }
        return maxc;
    }
};