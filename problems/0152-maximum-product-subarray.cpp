/*
 * Problem 0152: Maximum Product Subarray
 * URL     : https://leetcode.com/problems/maximum-product-subarray/
 * Solved  : 2026-06-24
 * Runtime : 364 ms
 * Memory  : 17.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro=nums[0];
        int temp=1;
        for(int i=0;i<nums.size();i++)
        {
            temp =1;
            for(int j=i;j<nums.size();j++)
            {
                temp*=nums[j];
                pro = max(pro,temp);
            }
        }
        return pro;
    }
};