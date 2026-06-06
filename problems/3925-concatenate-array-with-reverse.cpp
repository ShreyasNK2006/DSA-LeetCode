/*
 * Problem 3925: Concatenate Array With Reverse
 * URL     : https://leetcode.com/problems/concatenate-array-with-reverse/
 * Solved  : 2026-05-10
 * Runtime : 0 ms
 * Memory  : 30.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int> newarr(2*n);
        for(int i=0;i<n;i++)
            newarr[i]=nums[i];
        for(int i=0;i<n;i++)
            newarr[n+i]=nums[n-1-i];
        return newarr;
    }
};