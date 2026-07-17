/*
 * Problem 0787: Cheapest Flights Within K Stops
 * URL     : https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * Solved  : 2026-07-01
 * Runtime : 3 ms
 * Memory  : 17.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,src}});
        while(!q.empty())
        {
            int price= q.front().second.first;
            int node = q.front().second.second;
            int stops=q.front().first;
            q.pop();
            if(stops==k+1)
            continue;
            for(auto it:adj[node])
            {
                if(it.second+price<dist[it.first])
                {
                    dist[it.first]=it.second+price;
                    q.push({stops+1,{dist[it.first],it.first}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
        return -1;
        return dist[dst];
    }
};