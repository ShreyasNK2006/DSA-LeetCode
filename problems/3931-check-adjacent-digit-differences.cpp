/*
 * Problem 3931: Check Adjacent Digit Differences
 * URL     : https://leetcode.com/problems/check-adjacent-digit-differences/
 * Solved  : 2026-05-17
 * Runtime : 1 ms
 * Memory  : 8.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        bool cond=true;
        int i=0,n=s.size();
        while(cond && i<n-1)
            {
                if(abs(s[i+1]-s[i])>2)
                {
                    cond=false;
                }
                i++;
            }
        return cond;
    }
};