/*
 * Problem 0416: Partition Equal Subset Sum
 * URL     : https://leetcode.com/problems/partition-equal-subset-sum/
 * Solved  : 2026-09-28
 * Runtime : 203 ms
 * Memory  : 17.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total =0, n = nums.size();
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
        }
        if(total%2==1)
        return false;
        total/=2;
        vector<vector<bool>> dp(n+1,vector<bool>(total+1,false));
        for(int i=0;i<=n;i++)
        dp[i][0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=total;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1])
                dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][total];
    }
};