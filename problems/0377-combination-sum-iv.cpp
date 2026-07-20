/*
 * Problem 0377: Combination Sum IV
 * URL     : https://leetcode.com/problems/combination-sum-iv/
 * Solved  : 2026-06-04
 * Runtime : 4 ms
 * Memory  : 9.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public: 
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i>=nums[j])
                dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};