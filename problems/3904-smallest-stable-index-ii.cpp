/*
 * Problem 3904: Smallest Stable Index II
 * URL     : https://leetcode.com/problems/smallest-stable-index-ii/
 * Solved  : 2026-04-30
 * Runtime : 29 ms
 * Memory  : 202.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minn(n,INT_MAX);
        for(int i=n-1;i>=0;i--)
            {
                minn[i]=min(minn[i],nums[i]);
                if(i<n-1)
                {
                    minn[i]=min(minn[i],minn[i+1]);
                }
            }
        int maxn=INT_MIN;
        
        for(int i=0;i<n;i++)
            {
                maxn=max(maxn,nums[i]);
                if(maxn-minn[i]<=k)
                    return i;
            }
        return -1;
    }
};