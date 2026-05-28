/*
 * Problem 3922: Minimum Flips to Make Binary String Coherent
 * URL     : https://leetcode.com/problems/minimum-flips-to-make-binary-string-coherent/
 * Solved  : 2026-05-09
 * Runtime : 3 ms
 * Memory  : 19.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minFlips(string s) {
        int c=0;
        int zc=0,oc=0;
        for(auto c:s)
            {
                if(c=='1')
                    oc++;
                else
                    zc++;
            }
        int n=s.size();
        if(s[0]==s[n-1] && s[0]=='1')
        {
            oc--;
            n--;
        }
        if(oc>1 && zc>0)
        c=min(oc-1,zc);
        return c;
        
    }
};