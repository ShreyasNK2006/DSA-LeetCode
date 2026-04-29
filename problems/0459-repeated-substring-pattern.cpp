/*
 * Problem 0459: Repeated Substring Pattern
 * URL     : https://leetcode.com/problems/repeated-substring-pattern/
 * Solved  : 2026-04-22
 * Runtime : 4 ms
 * Memory  : 15.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    void computelps(string &s,vector<int> &lps)
    {
        int i=1,len=0;
        while(i<s.size())
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        computelps(s,lps);
        int len=n-lps[n-1];
        if(lps[n-1]>0 && n%(len)==0)
        return true;
        else
        return false;
    }
};