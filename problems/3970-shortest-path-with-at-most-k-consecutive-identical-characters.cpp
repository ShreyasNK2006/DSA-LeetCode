/*
 * Problem 3970: Shortest Path With At Most K Consecutive Identical Characters
 * URL     : https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
 * Solved  : 2026-06-30
 * Runtime : 207 ms
 * Memory  : 273.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;//weight,count,node
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        pq.push({{0,1},0});
        vector<vector<int>> dist(n,vector<int>(k,INT_MAX));
        dist[0][k-1]=0;
        while(!pq.empty())
        {
            int w=pq.top().first.first;
            int c=pq.top().first.second;
            int node= pq.top().second;
            pq.pop();
            for(auto x:adj[node])
            {
                if(labels[x.first]==labels[node])
                {
                    if(c<k)
                    {if(dist[x.first][k-c-1]>x.second+w)
                    {
                        dist[x.first][k-c-1]=x.second+w;
                        pq.push({{x.second+w,c+1},x.first});
                    }}
                }
                else
                {
                    if(dist[x.first][k-1]>x.second+w)
                    {
                        dist[x.first][k-1]=x.second+w;
                        pq.push({{x.second+w,1},x.first});
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<k;i++)
        ans=min(ans,dist[n-1][i]);
        return ans!=INT_MAX?ans:-1;
    }
};