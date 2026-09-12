/*
 * Problem 1927: Sum Game
 * URL     : https://leetcode.com/problems/sum-game/
 * Solved  : 2026-08-23
 * Runtime : 5 ms
 * Memory  : 13.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool sumGame(string num) {
        int ls=0;
        int n=num.size();
        int lq=0,rq=0;
        for(int i=0;i<n/2;i++)
        {
            if(num[i]!='?')
            ls+=(num[i]-'0');
            else
            lq++;
        }
        for(int i=n/2;i<n;i++)
        {
            if(num[i]!='?')
            ls-=(num[i]-'0');
            else
            rq++;
        }
        rq-=lq;
        //cout<<rq<<" "<<ls;
        if((rq*ls)>=0 && abs(ls) * 2 == 9 * abs(rq))
        return false;
        return true;
    }
};