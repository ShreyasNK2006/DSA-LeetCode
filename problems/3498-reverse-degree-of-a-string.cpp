/*
 * Problem 3498: Reverse Degree of a String
 * URL     : https://leetcode.com/problems/reverse-degree-of-a-string/
 * Solved  : 2026-09-20
 * Runtime : 0 ms
 * Memory  : 9.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int reverseDegree(string s) {
        int res=0,i=1;
        for(char c:s)
        {
            res+=((i)*(26-c+'a'));
            i++;
        }
        return res;
    }
};