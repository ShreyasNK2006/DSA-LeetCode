/*
 * Problem 3950: Exactly One Consecutive Set Bits Pair
 * URL     : https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/
 * Solved  : 2026-06-06
 * Runtime : 0 ms
 * Memory  : 7.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool consecutiveSetBits(int n) {
        bool found=false;
        int c=0;
        while(n)
            {
                if(n%2==0)
                    c=0;
                else
                    c++;
                if(c>=2 && found)
                    return false;
                else if(c==2)
                    found=true;
                n/=2;
            }
        return found;
    }
};