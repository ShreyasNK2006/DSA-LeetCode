/*
 * Problem 3993: Maximum Value of an Alternating Sequence
 * URL     : https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/
 * Solved  : 2026-07-18
 * Runtime : 0 ms
 * Memory  : 9.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans=0;
        if(n%2==1)
            n--;
        {
            ans= 1LL*s+ 1LL*(n/2)*m-1LL*(n-1)/2;
        }
        /*else
        {
            ans=1LL*s+ 1LL*((n-1)/2)*m -1LL*n/2;
        }*/
        return ans;
    }
};