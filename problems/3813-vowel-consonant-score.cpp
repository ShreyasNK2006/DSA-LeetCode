/*
 * Problem 3813: Vowel-Consonant Score
 * URL     : https://leetcode.com/problems/vowel-consonant-score/
 * Solved  : 2026-05-16
 * Runtime : 0 ms
 * Memory  : 9.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int vowelConsonantScore(string s) {
        int sc=0,c=0,v=0;
        unordered_set<char> st={'a','e','i','o','u'};
        for(char cr:s)
            {
                if(st.find(cr)!=st.end())
                    v++;
                else if(cr>='a' && cr<='z')
                    c++;
            }
        if(c>0)
        {
            sc=(v/c);
        }
        return sc;
    }
};