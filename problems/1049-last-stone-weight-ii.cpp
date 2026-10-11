/*
 * Problem 1049: Last Stone Weight II
 * URL     : https://leetcode.com/problems/last-stone-weight-ii/
 * Solved  : 2026-07-18
 * Runtime : 3 ms
 * Memory  : 12.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int ts=0;
        for(auto x:stones)
        ts+=x;
        int target = ts/2;
        vector<int> prev(target+1,0);
        int n=stones.size();
        prev[0]=1;
        for(int i=0;i<n;i++)
        {
            vector<int> curr(target+1,0);
            for(int j=0;j<=target;j++)
            {   
                if(j>=stones[i])
                curr[j]=prev[j-stones[i]]+prev[j];
                else
                curr[j]=prev[j];
            }
            prev=curr;
        }
        for(int i=target;i>=0;i--)
        {
            if(prev[i]!=0)
            {
                return ts-2*i;
            }
        }
        return ts;
    }
};