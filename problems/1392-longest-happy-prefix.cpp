/*
 * Problem 1392: Longest Happy Prefix
 * URL     : https://leetcode.com/problems/longest-happy-prefix/
 * Solved  : 2026-04-22
 * Runtime : 11 ms
 * Memory  : 24.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> computelps(string &s)
    {
        int n=s.size();
        vector<int> lps(n,0);
        int i=1,len=0;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else if(len!=0)
            len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
        vector<int> lps = computelps(s);
        int len=lps[s.size()-1];
        string res="";
        for(int i=0;i<len;i++)
        res.push_back(s[i]);
        return res;
    }
};