/*
 * Problem 3737: Count Subarrays With Majority Element I
 * URL     : https://leetcode.com/problems/count-subarrays-with-majority-element-i/
 * Solved  : 2026-06-25
 * Runtime : 44 ms
 * Memory  : 39.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int tempcount=0,count=0,size;
        for(int i=0;i<nums.size();i++)
            {
                tempcount=0;
                for(int j=i;j<nums.size();j++)
                    {
                        if(nums[j]==target)
                            tempcount++;
                        size=(j-i+1)/2;
                        if(size<tempcount)
                            count++;
                    }
            }
        return count;
    }
};