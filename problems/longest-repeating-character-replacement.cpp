/*
 * Problem: Longest Repeating Character Replacement
 * Solved on: 2025-11-12
 * Runtime: 0 ms
 * Memory: 10.8 MB
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0;
        int maxcount=0;
        int minfreq=0;
        vector<int> freq(26,0);
        while(right<s.length())
        {
            freq[s[right]-'A']++;
            minfreq =max(minfreq,freq[s[right]-'A']);
            while(right-left+1-minfreq>k)
            {
                freq[s[left]-'A']--;
                left++;
            }
            maxcount=max(maxcount,right-left+1);
            right++;
        }
        return maxcount;
    }
};