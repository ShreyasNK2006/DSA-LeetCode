/*
 * Problem 2294: Partition Array Such That Maximum Difference Is K
 * URL     : https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
 * Solved  : 2026-09-30
 * Runtime : 34 ms
 * Memory  : 96.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int c=1;
        int minn=nums[0];
        for(int i=0;i<n;i++)
        {
                if(nums[i]-minn>k)
                {
                    c++;
                    minn=nums[i];
                }
        }
        return c;
    }
};