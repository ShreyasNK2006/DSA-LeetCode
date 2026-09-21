/*
 * Problem 3499: Maximize Active Section with Trade I
 * URL     : https://leetcode.com/problems/maximize-active-section-with-trade-i/
 * Solved  : 2026-07-21
 * Runtime : 86 ms
 * Memory  : 54.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int count=0;
        for(char c:s)
        {
            if(c=='1')
            count++;
        }
        int zs=-1,ze=-1,os=-1,oe=-1;
        int maxc=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                if(zs==-1)
                zs=i;
                if(os!=-1)
                ze=i;
            }
            else
            {
                if(zs==-1)
                continue;
                if(os==-1)
                os=i;
                if(ze==-1)
                oe=i;
                else
                {
                    os=i;
                    zs=oe+1;
                    oe=i;
                    ze=-1;
                }
            }
            maxc=max(maxc,ze-oe+os-zs);
        }
        return count+maxc;
    }
};