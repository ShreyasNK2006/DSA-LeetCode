/*
 * Problem 3558: Number of Ways to Assign Edge Weights I
 * URL     : https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/
 * Solved  : 2026-06-11
 * Runtime : 302 ms
 * Memory  : 332.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define MOD 1000000007
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=0;
        for(int i=0;i<edges.size();i++)
        {
            n=max(n,max(edges[i][0],edges[i][1]));
        }
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int d=0;
        queue<int> q;
        q.push(1);
        vector<int> visited(n+1,0);
        visited[1]=1;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                for(auto it:adj[q.front()])
                {
                    if(!visited[it])
                    {
                        visited[it]=1;
                        q.push(it);
                    }
                }
                q.pop();
            } 
            d++;
        }
        int k=d-1;
        long long ans=1;
        for(int l=1;l<=k-1;l++)
        ans=(2*ans)%MOD;
        return ans;
    }
};