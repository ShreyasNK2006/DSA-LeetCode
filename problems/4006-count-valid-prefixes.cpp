/*
 * Problem 4006: Count Valid Prefixes
 * URL     : https://leetcode.com/problems/count-valid-prefixes/
 * Solved  : 2026-08-13
 * Runtime : 0 ms
 * Memory  : 9.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countValidPrefixes(string s) {
        int oc=0,zc=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
            {
                if(s[i]=='0')
                    oc++;
                else
                    zc++;
                if(abs(zc-oc)<=1)
                   ans++; 
            }
        return ans;
    }
};