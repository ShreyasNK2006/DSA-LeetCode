/*
 * Problem 0153: Find Minimum in Rotated Sorted Array
 * URL     : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Solved  : 2026-05-15
 * Runtime : 0 ms
 * Memory  : 13.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
       int low =0,high=nums.size()-1,mid;
       mid = (low+high)/2;
       int minn=nums[0];
       while(low<=high)
       {
            mid = (low+high)/2;    
            if(minn>nums[mid])
            {
                high=mid-1;
                minn =min(minn,nums[mid]);
            }
            else
            {
                low=mid+1;
                minn=min(minn,nums[mid]);
            }
       } 
       return minn;
    }
};