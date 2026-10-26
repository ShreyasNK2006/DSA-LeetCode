/*
 * Problem 0973: K Closest Points to Origin
 * URL     : https://leetcode.com/problems/k-closest-points-to-origin/
 * Solved  : 2026-09-26
 * Runtime : 62 ms
 * Memory  : 77.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(auto it: points)
        {
            double d = sqrt(it[0]*it[0]+it[1]*it[1]);
            pq.push({d,{it[0],it[1]}});
        }
        vector<vector<int>> res;
        for(int i=0;i<k && !pq.empty();i++)
        {
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};