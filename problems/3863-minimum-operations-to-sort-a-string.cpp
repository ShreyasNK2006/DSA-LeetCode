/*
 * Problem 3863: Minimum Operations to Sort a String
 * URL     : https://leetcode.com/problems/minimum-operations-to-sort-a-string/
 * Solved  : 2026-03-08
 * Runtime : 131 ms
 * Memory  : 35.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minOperations(string s) {
        string c = s;
        sort(c.begin(), c.end());
        string c2=s;
        if (c != s && s.size() == 2)
            return -1;
        if (c == s)
            return 0;
        if((s[0]==c[0])||(s[s.size()-1]==c[s.size()-1]))
        return 1;
        else
        {
            sort(c2.begin()+1,c2.end());
            sort(c2.begin(),c2.end()-1);
            if(c2==c)
            return 2;
            sort(s.begin(),s.end()-1);
            sort(s.begin()+1,s.end());
            if(s==c)
            return 2;
            else
            return 3;
        }
    }
};