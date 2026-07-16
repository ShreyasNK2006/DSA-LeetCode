/*
 * Problem 3945: Digit Frequency Score
 * URL     : https://leetcode.com/problems/digit-frequency-score/
 * Solved  : 2026-05-31
 * Runtime : 3 ms
 * Memory  : 9.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> mp;
        int s=0;
        while(n)
            {
                mp[n%10]++;
                n/=10;
            }
        for(auto it:mp)
            s+=it.first*it.second;
        return s;
    }
};