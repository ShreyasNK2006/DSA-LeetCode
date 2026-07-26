/*
 * Problem 3974: Maximum Total Sum of K Selected Elements
 * URL     : https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
 * Solved  : 2026-06-28
 * Runtime : 199 ms
 * Memory  : 188.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());
        int i=0;
        long long ts=0;
        while(mul>0 && i<nums.size() && k>0)
            {
                ts=ts+1LL*mul*nums[i];
                mul--;
                i++;
                k--;
            }
        while(i<nums.size() && k>0)
            {
                ts=ts+nums[i];
                i++;
                k--;
            }
        return ts;
    }
};