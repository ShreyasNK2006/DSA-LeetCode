/*
 * Problem 0486: Predict the Winner
 * URL     : https://leetcode.com/problems/predict-the-winner/
 * Solved  : 2026-05-17
 * Runtime : 0 ms
 * Memory  : 10.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        dp[i][i]=nums[i];
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j=i+len-1;
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};