/*
 * Problem 2784: Check if Array is Good
 * URL     : https://leetcode.com/problems/check-if-array-is-good/
 * Solved  : 2026-05-14
 * Runtime : 0 ms
 * Memory  : 26.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int sq=0,sum=0, asq=0,asum=0;
        int n=nums.size();
        sum= (n*(n-1))/2+n-1;
        sq=((n-1)*(n)*(2*n-1))/6 + (n-1)*(n-1);
        for(int i=0;i<n;i++)
        {
            asum+=nums[i];
            asq+=(nums[i]*nums[i]);
        }
        if(sum==asum && sq==asq)
        return true;
        else
        return false;
    }
};