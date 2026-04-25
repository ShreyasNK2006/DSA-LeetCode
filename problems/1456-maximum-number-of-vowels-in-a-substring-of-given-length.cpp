/*
 * Problem 1456: Maximum Number of Vowels in a Substring of Given Length
 * URL     : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 * Solved  : 2026-04-14
 * Runtime : 8 ms
 * Memory  : 13.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        queue<char> q;
        int i=0;
        int len=0;
        unordered_set<char>st;
        st.insert({'a','e','i','o','u'});
        while(i<k)
        {
            if(st.find(s[i])!=st.end())
            len++;
            i++;
        }
        int maxlen=len;
        if(len==k)
        return k;
        for(i=k;i<s.size();i++)
        {
            if(st.find(s[i-k])!=st.end())
            len--;
            if(st.find(s[i])!=st.end())
            len++;
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};