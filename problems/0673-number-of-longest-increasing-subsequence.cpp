/*
 * Problem 0673: Number of Longest Increasing Subsequence
 * URL     : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 * Solved  : 2026-04-05
 * Runtime : 20 ms
 * Memory  : 17.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),count(n,1);
        int maxlen=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else if(dp[i]==dp[j]+1)
                    {
                        count[i]+=count[j];
                    }
                }
            }
            if(maxlen<dp[i])
            {
                maxlen=dp[i];
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxlen)
            c+=count[i];
        }
        return c;
    }
};