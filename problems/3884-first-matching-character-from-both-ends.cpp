/*
 * Problem 3884: First Matching Character From Both Ends
 * URL     : https://leetcode.com/problems/first-matching-character-from-both-ends/
 * Solved  : 2026-03-29
 * Runtime : 0 ms
 * Memory  : 9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int firstMatchingIndex(string s) {
        int i=-1;
        for(int j=0;j<s.size();j++)
            {
                if(s[j]==s[s.size()-1-j])
                {
                    i=j;
                    break;
                }
            }
        return i;
    }
};