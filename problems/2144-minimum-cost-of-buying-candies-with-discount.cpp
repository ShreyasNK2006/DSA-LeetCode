/*
 * Problem 2144: Minimum Cost of Buying Candies With Discount
 * URL     : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
 * Solved  : 2026-06-01
 * Runtime : 0 ms
 * Memory  : 14.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int minc=0;
        sort(cost.begin(),cost.end());
        int n=cost.size();
        minc=cost[n-1];
        if(n>1)
        minc+=cost[n-2];
        for(int i=n-4;i>=0;i-=3)
        {
            minc+=cost[i];
            if(i>0)
            minc+=cost[i-1];
        }
        return minc;
    }
};