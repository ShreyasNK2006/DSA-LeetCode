/*
 * Problem 3512: Minimum Operations to Make Array Sum Divisible by K
 * URL     : https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
 * Solved  : 2026-06-05
 * Runtime : 0 ms
 * Memory  : 45.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum=0;
        for(int x:nums)
        sum+=x;
        return sum%k;
    }
};