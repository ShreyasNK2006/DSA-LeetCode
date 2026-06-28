/*
 * Problem 1732: Find the Highest Altitude
 * URL     : https://leetcode.com/problems/find-the-highest-altitude/
 * Solved  : 2026-06-19
 * Runtime : 0 ms
 * Memory  : 10.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxalt=0;
        int alt=0;
        for(auto it:gain)
        {
            alt=alt+it;
            maxalt=max(maxalt,alt);
        }
        return maxalt;
    }
};