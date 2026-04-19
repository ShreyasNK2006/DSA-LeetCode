/*
 * Problem 0390: Elimination Game
 * URL     : https://leetcode.com/problems/elimination-game/
 * Solved  : 2026-04-03
 * Runtime : 0 ms
 * Memory  : 9.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int lastRemaining(int n) {
        int shift=1;
        int remaining=n;
        bool left=true;
        int st=1;
        while(remaining>1)
        {
            if(left || remaining%2==1)
            st+=shift;
            shift*=2;
            remaining/=2;
            left=!left;
        }
        return st;
    }
};