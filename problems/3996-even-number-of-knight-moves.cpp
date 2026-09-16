/*
 * Problem 3996: Even Number of Knight Moves
 * URL     : https://leetcode.com/problems/even-number-of-knight-moves/
 * Solved  : 2026-08-22
 * Runtime : 0 ms
 * Memory  : 49.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return (((start[0]+start[1])%2)==((target[0]+target[1])%2));
    }
};