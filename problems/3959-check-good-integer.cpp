/*
 * Problem 3959: Check Good Integer
 * URL     : https://leetcode.com/problems/check-good-integer/
 * Solved  : 2026-06-14
 * Runtime : 0 ms
 * Memory  : 7.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool checkGoodInteger(int n) {
        long long ss=0,ds=0;
        while(n)
            {
                ss=ss+1LL*(n%10)*(n%10);
                ds=ds+n%10;
                n/=10;
            }
        return (ss-ds)>=50;
    }
};