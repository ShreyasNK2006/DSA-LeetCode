/*
 * Problem 3914: Minimum Operations to Make Array Non Decreasing
 * URL     : https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing/
 * Solved  : 2026-05-06
 * Runtime : 12 ms
 * Memory  : 137 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        int maxn=nums[0];

        for(int i=1;i<n;i++)
            {
                sum=sum+1LL*(max(maxn,nums[i])-nums[i]);
                maxn=nums[i];
            }
        return sum;
    }
};