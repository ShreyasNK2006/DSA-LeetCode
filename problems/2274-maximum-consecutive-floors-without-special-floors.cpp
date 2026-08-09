/*
 * Problem 2274: Maximum Consecutive Floors Without Special Floors
 * URL     : https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
 * Solved  : 2026-07-13
 * Runtime : 28 ms
 * Memory  : 61.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int maxf=0;
        int c=0;
        sort(special.begin(),special.end());
        for(int i=0;i<special.size();i++)
            {
                if(i==0)
                {
                    c=special[i]-bottom;
                    maxf=max(maxf,c);
                }
                if(i==special.size()-1)
                {
                    c=top-special[i];
                    maxf=max(maxf,c);
                }
                if(i!=0)
                    c=special[i]-special[i-1]-1;
                maxf=max(maxf,c);
                
            }
        return maxf;
    }
};