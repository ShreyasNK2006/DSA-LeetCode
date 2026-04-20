/*
 * Problem 0312: Burst Balloons
 * URL     : https://leetcode.com/problems/burst-balloons/
 * Solved  : 2026-04-05
 * Runtime : 91 ms
 * Memory  : 14 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                int profit=INT_MIN;
                for(int k=i+1;k<j;k++)
                {
                    profit=max(profit,nums[i]*nums[k]*nums[j]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][n-1];
    }
};