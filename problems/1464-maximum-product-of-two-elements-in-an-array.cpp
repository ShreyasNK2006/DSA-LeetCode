/*
 * Problem 1464: Maximum Product of Two Elements in an Array
 * URL     : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 * Solved  : 2026-07-27
 * Runtime : 0 ms
 * Memory  : 13.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxn=0,smaxn=0;
        for(int x:nums)
        {
            if(x>maxn)
            {
                smaxn=maxn;
                maxn=x;
            }
            else if(x>smaxn)
            {
                smaxn=x;
            }
        }
        return (maxn-1)*(smaxn-1);
    }
};