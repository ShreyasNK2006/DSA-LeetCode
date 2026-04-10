/*
 * Problem 2839: Check if Strings Can be Made Equal With Operations I
 * URL     : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
 * Solved  : 2026-03-29
 * Runtime : 0 ms
 * Memory  : 8.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=2;i<s1.size();i++)
        {
            char a=s1[i],b=s2[i],c=s1[i-2],d=s2[i-2];
            if((a==b && c==d)||(a==d && c==b))
            continue;
            else return false;
        }
        return true;
    }
};