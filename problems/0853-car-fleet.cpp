/*
 * Problem 0853: Car Fleet
 * URL     : https://leetcode.com/problems/car-fleet/
 * Solved  : 2026-05-01
 * Runtime : 59 ms
 * Memory  : 107.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pr;
        int n=position.size();
        for(int i=0;i<n;i++)
        {
            pr.push_back({position[i],speed[i]});
        }
        sort(pr.rbegin(),pr.rend());
        int c=0;
        for(int i=0;i<n;)
        {
            c++;
            double t=(1.0*target-pr[i].first)/pr[i].second;
            int j=i+1;
            while(j<n && t>=(1.0*target-pr[j].first)/pr[j].second)
            {
                j++;
            }
            i=j;
        }
        return c;
    }
};