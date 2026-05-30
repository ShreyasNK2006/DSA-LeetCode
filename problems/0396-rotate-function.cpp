/*
 * Problem 0396: Rotate Function
 * URL     : https://leetcode.com/problems/rotate-function/
 * Solved  : 2026-05-01
 * Runtime : 0 ms
 * Memory  : 99.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f=0,total=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            f+=(i*nums[i]);
            total+=nums[i];
        }
        int maxf=f;
        for(int i=0;i<n;i++)
        {
            f=f+(total-n*nums[n-1-i]);
            maxf=max(maxf,f);
        }
        return maxf;
    }
};