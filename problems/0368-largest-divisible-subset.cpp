/*
 * Problem 0368: Largest Divisible Subset
 * URL     : https://leetcode.com/problems/largest-divisible-subset/
 * Solved  : 2026-04-04
 * Runtime : 12 ms
 * Memory  : 12.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1),parent(n);
        int lastind=0;
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(maxlen<dp[i])
            {
                maxlen=dp[i];
                lastind=i;
            }
        }
        vector<int> res(maxlen);
        for(int i=maxlen-1;i>=0;i--)
        {
            res[i]=nums[lastind];
            lastind=parent[lastind];
        }
        return res;
    }
};