/*
 * Problem: Partition Equal Subset Sum
 * Solved on: 2025-11-12
 * Runtime: 87 ms
 * Memory: 13.4 MB
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            totalsum+=nums[i];
        }
        if(totalsum%2!=0)
        return false;
        totalsum/=2;
        vector<bool> dp(totalsum+1,false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++)
        {
            for(int s=totalsum;s>=nums[i];s--)
            {
                dp[s] = dp[s]||dp[s-nums[i]];
            }
        }
        return dp[totalsum];
    }
};