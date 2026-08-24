/*
 * Problem 1189: Maximum Number of Balloons
 * URL     : https://leetcode.com/problems/maximum-number-of-balloons/
 * Solved  : 2026-06-22
 * Runtime : 0 ms
 * Memory  : 9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);
        for(char c:text)
        {
            freq[c-'a']++;
        }
        freq['l'-'a']/=2;
        freq['o'-'a']/=2;
        int ans=INT_MAX;
        ans=min(ans,min(freq['b'-'a'],min(freq[0],min(freq['l'-'a'],min(freq['o'-'a'],freq['n'-'a'])))));
        return ans;
    }
};