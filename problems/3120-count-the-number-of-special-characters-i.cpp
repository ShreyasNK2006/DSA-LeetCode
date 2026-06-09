/*
 * Problem 3120: Count the Number of Special Characters I
 * URL     : https://leetcode.com/problems/count-the-number-of-special-characters-i/
 * Solved  : 2026-05-26
 * Runtime : 0 ms
 * Memory  : 9.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> count1(26,0),count2(26,0);
        int count=0;
        for(char c:word)
        {
            if(c>='a' && c<='z')
            {
                count1[c-'a']++;
            }
            if(c>='A' && c<='Z')
            {
                count2[c-'A']++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(min(count1[i],count2[i])>=1)
            count++;
        }
        return count;
    }
};