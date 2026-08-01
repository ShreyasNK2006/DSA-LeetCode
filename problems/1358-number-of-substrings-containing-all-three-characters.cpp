/*
 * Problem 1358: Number of Substrings Containing All Three Characters
 * URL     : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 * Solved  : 2026-06-30
 * Runtime : 7 ms
 * Memory  : 11 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1;
        int count=0,temp;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
            a=i;
            else if(s[i]=='b')
            b=i;
            else if(s[i]=='c')
            c=i;
            if(a>-1 && b>-1 && c>-1)
            {
                temp=min(a,min(b,c));
                count+=(temp+1);
            }
        }
        return count;
    }
};