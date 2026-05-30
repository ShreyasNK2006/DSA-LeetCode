/*
 * Problem 0287: Find the Duplicate Number
 * URL     : https://leetcode.com/problems/find-the-duplicate-number/
 * Solved  : 2026-05-01
 * Runtime : 2 ms
 * Memory  : 67.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq (n,0);
        for(int x:nums)
        {
            if(freq[x]==1)
            return x;
            freq[x]++;
        }
        return n;
    }
};