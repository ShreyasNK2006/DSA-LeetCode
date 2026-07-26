/*
 * Problem 3965: Finish Time of Tasks I
 * URL     : https://leetcode.com/problems/finish-time-of-tasks-i/
 * Solved  : 2026-06-27
 * Runtime : 119 ms
 * Memory  : 337.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    void dfs(int n,vector<vector<int>> &adj,vector<pair<long long,long long>>& cv,vector<int>& bt,int node)
    {
        if(adj[node].size()==0)
        {
            return;
        }
        for(int j=0;j<adj[node].size();j++)
        {
            dfs(n,adj,cv,bt,adj[node][j]);
            long long od= (cv[adj[node][j]].second-cv[adj[node][j]].first+bt[adj[node][j]]);
            cv[node].first=min(cv[node].first,od+cv[adj[node][j]].second);
            cv[node].second=max(cv[node].second,od+cv[adj[node][j]].second);
        }
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& bt) {
        vector<vector<int>> adj(n);
        vector<pair<long long,long long>> cv(n,{LLONG_MAX,LLONG_MIN});
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==0)
            cv[i]={0,0};
        }
        for(int i=0;i<adj[0].size();i++)
        {
            dfs(n,adj,cv,bt,adj[0][i]);
            long long od= (cv[adj[0][i]].second-cv[adj[0][i]].first+bt[adj[0][i]]);
            cv[0].first=min(cv[0].first,od+cv[adj[0][i]].second);
            cv[0].second=max(cv[0].second,od+cv[adj[0][i]].second);
        }
        return 2*cv[0].second-cv[0].first+bt[0];
    }
};