/*
 * Problem 3090: Maximum Length Substring With Two Occurrences
 * URL     : https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
 * Solved  : 2026-08-14
 * Runtime : 14 ms
 * Memory  : 26.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen=0;
        vector<queue<int>> freq(26);
        int l=-1;
        for(int i=0;i<s.size();i++)
        {
            int c = s[i]-'a';
            if(freq[c].size()==2)
            {
                for(int j=l+1;j<freq[c].front();j++)
                {
                    freq[s[j]-'a'].pop();
                }
                l=freq[c].front();
                freq[c].pop();
                
            }
            maxlen=max(maxlen,i-l);
            freq[c].push(i);
        }
        return maxlen;
    }
};