/*
 * Problem 4000: Largest Integer With Given Digit Sum
 * URL     : https://leetcode.com/problems/largest-integer-with-given-digit-sum/
 * Solved  : 2026-08-14
 * Runtime : 0 ms
 * Memory  : 8.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int largestInteger(int n, int s) {
        int res=0;
        int d=0;
        while(d<n)
            {
                d++;
                res*=10;
                if(s<10)
                {
                    res+=s;
                    s=0;
                }
                else 
                {
                    res+=9;
                    s-=9;
                }
            }
        return s==0?res:-1;
    }
};