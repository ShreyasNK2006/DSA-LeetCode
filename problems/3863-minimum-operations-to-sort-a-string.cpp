/*
 * Problem 3863: Minimum Operations to Sort a String
 * URL     : https://leetcode.com/problems/minimum-operations-to-sort-a-string/
 * Solved  : 2026-03-08
 * Runtime : 11 ms
 * Memory  : 27.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool sortfind(string &s)
    {
        int prev=s[0];
        for(int i=1;i<s.size();i++)
        {
            if(prev>s[i])
            return false;
            prev=s[i];
        }
        return true;
    }
    int minOperations(string s) {
        bool sorted=sortfind(s);
        if(sorted)
        return 0;
        if(s.size()==2)
        return -1;
        char small='z',big='a';
        int sind=INT_MAX,bind=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<small)
            {
                small=s[i];
                sind=i;
            }
            if(s[i]>=big)
            {
                big=s[i];
                bind=i;
            }
        }
        if(sind==0 || bind==s.size()-1)
        return 1;
        else if(sind==s.size()-1 && bind==0)
        return 3;
        else
        return 2;
    }
};