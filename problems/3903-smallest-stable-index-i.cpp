/*
 * Problem 3903: Smallest Stable Index I
 * URL     : https://leetcode.com/problems/smallest-stable-index-i/
 * Solved  : 2026-04-30
 * Runtime : 0 ms
 * Memory  : 31 MB
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