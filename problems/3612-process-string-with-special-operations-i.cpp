/*
 * Problem 3612: Process String with Special Operations I
 * URL     : https://leetcode.com/problems/process-string-with-special-operations-i/
 * Solved  : 2026-06-16
 * Runtime : 2 ms
 * Memory  : 39.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string processStr(string s) {
        string res;
        for(char c:s)
        {
            if(c>='a' && c<='z')
            res.push_back(c);
            else if(c== '*' && res.size()!=0)
            res.erase(res.size()-1);
            else if(c=='#')
            res+=res;
            else if(c=='%')
            reverse(res.begin(),res.end());
        }
        return res;
    }
};