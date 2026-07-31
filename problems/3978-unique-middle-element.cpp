/*
 * Problem 3978: Unique Middle Element
 * URL     : https://leetcode.com/problems/unique-middle-element/
 * Solved  : 2026-07-04
 * Runtime : 0 ms
 * Memory  : 31.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid= nums[nums.size()/2];
        int f=0;
        for(int x:nums)
        {
            if(x==mid)
                f++;
        }
        return f==1;
    }
};