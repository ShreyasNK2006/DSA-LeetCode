/*
 * Problem 4008: Minimum Initial Strength to Defeat All Monsters
 * URL     : https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/
 * Solved  : 2026-08-14
 * Runtime : 4 ms
 * Memory  : 247.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        int m=boosts.size();
        vector<long long>diff(n+1,0),bonus(n,0);
        for(int i=0;i<m;i++)
        {
            diff[boosts[i][0]]+=boosts[i][2];
            diff[boosts[i][1]+1]-=boosts[i][2];
        }
        bonus[0]=diff[0];
        for(int i=1;i<n;i++)
        {
            bonus[i]=bonus[i-1]+diff[i];
        }
        long long req=0;
        for(int i=n-1;i>=0;i--)
        {
            if(req==0)
            {
                if(bonus[i]>=monsters[i])
                continue;
                else
                req+=(1LL*monsters[i]-bonus[i]);
            }
            else
            {
                req+=(1LL*monsters[i]);
            }
        }
        return req;
    }
};