/*
 * Problem 0200: Number of Islands
 * URL     : https://leetcode.com/problems/number-of-islands/
 * Solved  : 2026-04-03
 * Runtime : 31 ms
 * Memory  : 18.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> parent,rank;
    int find(int u)
    {
        if(parent[u]==u)
        return u;
        else
        return parent[u]=find(parent[u]);
    }
    void unions(int u,int v)
    {
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)
        return;
        else if(rank[pu]>rank[pv])
        {
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        parent.resize(m*n);
        rank.resize(m*n,1);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                parent[i*n+j]=i*n+j;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(i<m-1 && grid[i+1][j]=='1')
                    unions(i*n+j,(i+1)*n+j);
                    if(j<n-1 && grid[i][j+1]=='1')
                    unions(i*n+j,i*n+j+1);
                }
            }
        }
        unordered_set<int> st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                st.insert(find(i*n+j));
            }
        }
        return st.size();
    }
};