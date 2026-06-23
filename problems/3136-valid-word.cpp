/*
 * Problem 3136: Valid Word
 * URL     : https://leetcode.com/problems/valid-word/
 * Solved  : 2026-04-15
 * Runtime : 0 ms
 * Memory  : 8.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool isValid(string word) {
        bool valid=true;
        unordered_set<char> st ={'a','e','i','o','u','A','E','I','O','U'};
        int vc=0;
        int n=word.size();
        int num=0;
        for(int i=0;i<n;i++)
        {
            if(!((word[i]>=48 && word[i]<=57)|| (word[i]>=65 && word[i]<=90)||(word[i]>=97 && word[i]<=122)))
            return false;
            if(st.find(word[i])!=st.end())
            vc++;
            else if(word[i]>=48 && word[i]<=57)
            num++;
        }
        if(vc>0 && vc+num<n && n>=3)
        return true;
        return false;
    }
};