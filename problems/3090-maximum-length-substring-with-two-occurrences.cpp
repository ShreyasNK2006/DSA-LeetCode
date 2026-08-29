/*
 * Problem 3090: Maximum Length Substring With Two Occurrences
 * URL     : https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
 * Solved  : 2026-08-14
 * Runtime : 0 ms
 * Memory  : 9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen=0;
        vector<int> freq(26,0);
        int l=-1;
        for(int i=0;i<s.size();i++)
        {
            int c = s[i]-'a';
            if(freq[c]==2)
            {
                for(int j=l+1;(s[j]-'a')!=c;j++)
                {
                    freq[s[j]-'a']--;
                    l=j;
                }
                l++;
                freq[c]--;
            }
            maxlen=max(maxlen,i-l);
            freq[c]++;
        }
        return maxlen;
    }
};