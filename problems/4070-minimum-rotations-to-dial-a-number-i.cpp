/*
 * Problem 4070: Minimum Rotations to Dial a Number I
 * URL     : https://leetcode.com/problems/minimum-rotations-to-dial-a-number-i/
 * Solved  : 2026-10-04
 * Runtime : 0 ms
 * Memory  : 8.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minRotations(string s) {
        char curr='0';
        int r=0;
        for(auto it: s)
            {
                int s = min(abs(it-curr),abs(10-abs(it-curr)));
                r+=s;
                curr=it;
            }
        return r;
    }
};