/*
 * Problem 0154: Find Minimum in Rotated Sorted Array II
 * URL     : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * Solved  : 2026-05-16
 * Runtime : 1 ms
 * Memory  : 16.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int minn=nums[0];
        for(int i=0;i<n;i++)
        minn=min(minn,nums[i]);
        return minn;
    }
};