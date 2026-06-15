/*
 * Problem 3732: Maximum Product of Three Elements After One Replacement
 * URL     : https://leetcode.com/problems/maximum-product-of-three-elements-after-one-replacement/
 * Solved  : 2026-05-16
 * Runtime : 46 ms
 * Memory  : 124.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long prod=100000;
        int n=nums.size();
        for(int i=0;i<n;i++)
            {
                nums[i]=abs(nums[i]);
            }
        sort(nums.begin(),nums.end());
        prod=prod*nums[n-1]*nums[n-2];
        return prod;
    }
};