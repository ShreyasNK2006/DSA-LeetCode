/*
 * Problem 3689: Maximum Total Subarray Value I
 * URL     : https://leetcode.com/problems/maximum-total-subarray-value-i/
 * Solved  : 2026-06-09
 * Runtime : 0 ms
 * Memory  : 103.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        int minn=INT_MAX,maxn=INT_MIN;
        for(int x:nums)
        {
            minn=min(minn,x);
            maxn=max(maxn,x);
        }
        return 1LL*k*(maxn-minn);
    }
};