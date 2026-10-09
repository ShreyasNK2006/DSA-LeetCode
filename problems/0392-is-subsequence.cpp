/*
 * Problem 0392: Is Subsequence
 * URL     : https://leetcode.com/problems/is-subsequence/
 * Solved  : 2026-08-07
 * Runtime : 0 ms
 * Memory  : 8.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,n=s.size();
        for(char c:t)
        {
            if(i==n)
            break;
            if(c==s[i])
            {
                i++;
            }
        }
        return i==n;
    }
};