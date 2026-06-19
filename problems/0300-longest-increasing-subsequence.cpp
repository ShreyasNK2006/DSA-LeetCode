/*
 * Problem 0300: Longest Increasing Subsequence
 * URL     : https://leetcode.com/problems/longest-increasing-subsequence/
 * Solved  : 2026-04-05
 * Runtime : 56 ms
 * Memory  : 14.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> len(n,1);
        int maxlen=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && len[i]<len[j]+1)
                {
                    len[i]=len[j]+1;
                }
            }
            maxlen=max(maxlen,len[i]);
        }
        return maxlen;
    }
};