/*
 * Problem 1541: Minimum Insertions to Balance a Parentheses String
 * URL     : https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
 * Solved  : 2026-10-09
 * Runtime : 0 ms
 * Memory  : 15.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minInsertions(string s) {
        int open=0,closed=0;
        int cb=0;// '(' count
        int cons=0;
        int res=0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(cons>0)
                {
                    if(open>0)
                    {
                        open--;
                        res++;
                    }
                    else
                    res+=2;
                }
                cons=0;
                open++;
            }
            else
            {
                cons++;
                if(cons==2)
                {
                    cons=0;
                    if(open>0)
                    open--;
                    else
                    res++;
                }
            }
        }
        if(cons==1)
        {
            if(open>0)
            {
                res++;
                open--;
                cons=0;
            }
        }
        res+=2*open;
        res+=(cons/2 + 2*(cons%2));
        return res;
    }
};