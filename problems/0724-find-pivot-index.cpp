/*
 * Problem 0724: Find Pivot Index
 * URL     : https://leetcode.com/problems/find-pivot-index/
 * Solved  : 2026-04-29
 * Runtime : 2 ms
 * Memory  : 35.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            total-=nums[i];
            if(sum==total)
            return i;
            sum+=nums[i];
        }
        return -1;
    }
};