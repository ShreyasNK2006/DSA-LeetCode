/*
 * Problem: Coin Change
 * Solved on: 2025-11-13
 * Runtime: 11 ms
 * Memory: 17.8 MB
*/

class Solution {
public:
    void calcmincoin(vector<int>& coins, int amount,int &res)
    {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int coin:coins)
        {
            for(int x =coin;x<=amount;x++)
            {
                if(dp[x-coin]!=INT_MAX)
                dp[x]=min(dp[x-coin]+1,dp[x]);
            }
        }
        res=(dp[amount]==INT_MAX?-1:dp[amount]);
        return;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int res;
        calcmincoin(coins,amount,res);
        return res;
    }
};