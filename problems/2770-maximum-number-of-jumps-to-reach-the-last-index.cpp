/*
 * Problem 2770: Maximum Number of Jumps to Reach the Last Index
 * URL     : https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
 * Solved  : 2026-05-10
 * Runtime : 43 ms
 * Memory  : 71.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        map<long long,int> mp;
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            auto it=mp.lower_bound(1LL*nums[i]-target);
            for(;it!=mp.upper_bound(1LL*nums[i]+target);it++)
            dp[i]=max(dp[i],it->second+1);
            if(dp[i]!=-1)
            mp[nums[i]]=dp[i];
        }
        return dp[n-1];
    }
};