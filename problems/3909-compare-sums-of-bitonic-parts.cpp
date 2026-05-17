/*
 * Problem 3909: Compare Sums of Bitonic Parts
 * URL     : https://leetcode.com/problems/compare-sums-of-bitonic-parts/
 * Solved  : 2026-05-05
 * Runtime : 2 ms
 * Memory  : 125.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long ls=nums[0],rs=0;
        int ind=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
            {
                if(nums[i]>nums[i-1])
                {
                    ls+=1LL*nums[i];
                    ind=i;
                }
                else
                    break;
            }
        for(;ind<n;ind++)
            {
                rs+=1LL*nums[ind];
            }
        if(ls>rs)
            return 0;
        else if(ls<rs)
            return 1;
        else
            return -1;
    }
};