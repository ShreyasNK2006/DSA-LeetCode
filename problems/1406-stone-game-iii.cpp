/*
 * Problem 1406: Stone Game III
 * URL     : https://leetcode.com/problems/stone-game-iii/
 * Solved  : 2026-08-10
 * Runtime : 16 ms
 * Memory  : 146.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<=n)
            {
                dp[i]=(nums[i]-dp[i+1]);
            }
            if(i+2<=n)
            {
                dp[i]=max(dp[i],nums[i]+nums[i+1]-dp[i+2]);
            }
            if(i+3<=n)
            {
                dp[i]=max(dp[i],nums[i]+nums[i+1]+nums[i+2]-dp[i+3]);
            }
        }
        if(dp[0]>0)
        return "Alice";
        else if(dp[0]<0)
        return "Bob";
        else
        return "Tie";
    }
};