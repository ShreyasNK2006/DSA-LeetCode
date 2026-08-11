/*
 * Problem 3014: Minimum Number of Pushes to Type Word I
 * URL     : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
 * Solved  : 2026-07-30
 * Runtime : 0 ms
 * Memory  : 10.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minimumPushes(string word) {
        int c=0;
        vector<int> f(26,0);
        for(char c:word)
        {
            f[c-'a']++;
        }
        vector<int> sf;
        for(int i=0;i<26;i++)
        {
            if(f[i]>0)
            sf.push_back(f[i]);
        }
        sort(sf.rbegin(),sf.rend());
        int k=0,factor=1;
        for(auto x:sf)
        {
            c=c+factor*x;
            k++;
            if(k%8==0)
            factor++;
        }
        return c;
    }
};