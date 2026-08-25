/*
 * Problem 3992: Rearrange String to Avoid Character Pair
 * URL     : https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/
 * Solved  : 2026-07-18
 * Runtime : 3 ms
 * Memory  : 9.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string t;
        int fx=0,fy=0;
        for(char c:s)
            {
                if(c==x)
                    fx++;
                if(c==y)
                    fy++;
            }
        while(fy--)
            t+=y;
        while(fx--)
            t+=x;
        for(char c:s)
            {
                if(c!=x && c!=y)
                    t+=c;
            }
        return t;
    }
};