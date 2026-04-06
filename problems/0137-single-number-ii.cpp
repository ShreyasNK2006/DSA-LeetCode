/*
 * Problem 0137: Single Number II
 * URL     : https://leetcode.com/problems/single-number-ii/
 * Solved  : 2026-04-01
 * Runtime : 2 ms
 * Memory  : 14.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==1)
            return nums[i];
        }
        return 0;
    }
};