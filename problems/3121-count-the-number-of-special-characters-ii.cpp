/*
 * Problem 3121: Count the Number of Special Characters II
 * URL     : https://leetcode.com/problems/count-the-number-of-special-characters-ii/
 * Solved  : 2026-05-27
 * Runtime : 59 ms
 * Memory  : 24.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int c=0;
        vector<int> c1(26,0),c2(26,0),c3(26,0);
        vector<bool> special(26,false);
        for(char c:word)
        {
            if(c>='a' && c<='z')
            {
                c1[c-'a']++;
                special[c-'a']=true;
            }
            else
            c2[c-'A']++;
        }
        for(char c:word)
        {
            if(c>='a' && c<='z')
            {
                c3[c-'a']++;
                if(min(c1[c-'a'],c2[c-'a'])==0)
                {
                    special[c-'a']=false;
                }
            }
            else if(c3[c-'A']!=c1[c-'A'])
            {
                special[c-'A']=false;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(special[i])
            c++;
        }
        return c;
    }
};