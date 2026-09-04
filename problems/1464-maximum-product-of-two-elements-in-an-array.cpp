/*
 * Problem 1464: Maximum Product of Two Elements in an Array
 * URL     : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 * Solved  : 2026-07-27
 * Runtime : 0 ms
 * Memory  : 16.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        return (nums[0]-1)*(nums[1]-1);
    }
};