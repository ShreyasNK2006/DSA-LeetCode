/*
 * Problem 4034: Minimum Bishop Moves to Reach Target
 * URL     : https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/
 * Solved  : 2026-08-29
 * Runtime : 0 ms
 * Memory  : 50.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int count =0;
        if((source[0]+source[1])%2!=(target[0]+target[1])%2)
            return -1;
        if(abs(target[1]-source[1])==abs(target[0]-source[0]))
            return 1;
        else
            return 2;
    }
};