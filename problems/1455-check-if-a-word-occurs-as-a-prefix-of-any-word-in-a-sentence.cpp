/*
 * Problem 1455: Check If a Word Occurs As a Prefix of Any Word in a Sentence
 * URL     : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
 * Solved  : 2026-04-02
 * Runtime : 0 ms
 * Memory  : 8.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size(),m=searchWord.size();
        int word=1;
        for(int i=0;i<n-m+1;i++)
        {
            if(((i>0 && sentence[i-1]==' ')||(i==0)) && sentence.substr(i,m)==searchWord)
            return word;
            if(sentence[i]==' ')
            word++;
        }
        return -1;
    }
};