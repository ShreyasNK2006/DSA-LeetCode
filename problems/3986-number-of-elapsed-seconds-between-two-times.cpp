/*
 * Problem 3986: Number of Elapsed Seconds Between Two Times
 * URL     : https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/
 * Solved  : 2026-07-12
 * Runtime : 0 ms
 * Memory  : 9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        int s=0;
        s=(et[7]-st[7] + 10*(et[6]-st[6]) + 60*(et[4]-st[4] + 10*(et[3]-st[3]))+3600*(et[1]-st[1] + 10*(et[0]-st[0])));
        return s;
    }
};