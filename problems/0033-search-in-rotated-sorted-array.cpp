/*
 * Problem 0033: Search in Rotated Sorted Array
 * URL     : https://leetcode.com/problems/search-in-rotated-sorted-array/
 * Solved  : 2026-05-22
 * Runtime : 0 ms
 * Memory  : 15.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(target==nums[i])
            pos=i;   
        }
        return pos;
    }
};