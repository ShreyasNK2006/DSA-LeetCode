/*
 * Problem 1833: Maximum Ice Cream Bars
 * URL     : https://leetcode.com/problems/maximum-ice-cream-bars/
 * Solved  : 2026-06-21
 * Runtime : 35 ms
 * Memory  : 80.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int c=0;
        for(int i=0;i<costs.size();i++)
        {
            if(coins<costs[i])
            break;
            c++;
            coins-=costs[i];
        }
        return c;
    }
};