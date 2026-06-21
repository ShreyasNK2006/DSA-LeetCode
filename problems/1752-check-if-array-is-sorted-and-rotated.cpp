/*
 * Problem 1752: Check if Array Is Sorted and Rotated
 * URL     : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 * Solved  : 2026-05-23
 * Runtime : 0 ms
 * Memory  : 11.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        bool rotated=false;
        int n=nums.size(),i=1,prev=nums[0];
        while(i<n)
        {
           if(prev<=nums[i])
           {
            prev=nums[i];
            i++;
           }
           else
           break;
        }
        if(i<n)
        rotated=true;
        prev=nums[i];
        while(i<n)
        {
            if(prev<=nums[i])
            {
                prev=nums[i];
                i++;
            }
            else
            break;
        }
        if(i==n)
        {
            if(!rotated ||(rotated && nums[n-1]<=nums[0]))
            return true;
        }
        return false;
    }
};