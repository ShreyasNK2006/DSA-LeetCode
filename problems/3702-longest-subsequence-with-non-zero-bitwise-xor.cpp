/*
 * Problem 3702: Longest Subsequence With Non-Zero Bitwise XOR
 * URL     : https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
 * Solved  : 2026-08-15
 * Runtime : 0 ms
 * Memory  : 171.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res=0,zerocount=0;
        for(int ind=0;ind<nums.size();ind++)
            {
                    res^=nums[ind];
                    if(nums[ind]==0)
                        zerocount++;
            }
        if(res!=0)
            return nums.size();
        if(zerocount==nums.size())
            return 0;
            return nums.size()-1;
    }
    
};