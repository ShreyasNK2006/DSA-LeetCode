/*
 * Problem 3968: Maximum Manhattan Distance After All Moves
 * URL     : https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/
 * Solved  : 2026-06-21
 * Runtime : 11 ms
 * Memory  : 22.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxDistance(string moves) {
        int ans=0;
        int lf=0,rf=0,uf=0,df=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
                lf++;
            else if(moves[i]=='R')
                rf++;
            else if(moves[i]=='U')
                uf++;
            else if(moves[i]=='D')
                df++;
        }
        ans=abs(lf-rf)+abs(df-uf)+moves.size()-(lf+uf+rf+df);
        return ans;
    }
};