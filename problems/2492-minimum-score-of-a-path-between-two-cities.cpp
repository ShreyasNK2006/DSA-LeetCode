/*
 * Problem 2492: Minimum Score of a Path Between Two Cities
 * URL     : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 * Solved  : 2026-07-04
 * Runtime : 107 ms
 * Memory  : 146.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> visited(n+1,0);
        for(auto x:roads)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        int dist=INT_MAX;
        queue<int> q;
        q.push(1);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(visited[node])
            continue;
            visited[node]=1;
            for(auto x:adj[node])
            {
                if(visited[x.first])
                continue;
                dist=min(dist,x.second);
                q.push(x.first);
            }
        }
        return dist;
    }
};