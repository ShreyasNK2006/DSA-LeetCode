/*
 * Problem 3940: Limit Occurrences in Sorted Array
 * URL     : https://leetcode.com/problems/limit-occurrences-in-sorted-array/
 * Solved  : 2026-05-30
 * Runtime : 4 ms
 * Memory  : 33.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;
        int f=1;
        int st=nums[0];
        res.push_back(st);
        for(int i=1;i<nums.size();i++)
            {
                if(st==nums[i])
                    f++;
                else
                {
                    st=nums[i];
                    f=1;
                }
                if(f<=k)
                    res.push_back(nums[i]);
            }
    return res;
    }
};