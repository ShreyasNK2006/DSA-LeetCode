/*
 * Problem 0990: Satisfiability of Equality Equations
 * URL     : https://leetcode.com/problems/satisfiability-of-equality-equations/
 * Solved  : 2026-08-09
 * Runtime : 0 ms
 * Memory  : 15.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> parent,rank;
    int find(int u)
    {
        if(u==parent[u])
        return u;
        return parent[u]=find(parent[u]);
    }
    void union_by_rank(int u,int v)
    {
        int pu = find(u);
        int pv = find(v);
        if(rank[pu]<rank[pv])
        {
            parent[u]=pv;
        }
        else if(rank[pu]>rank[pv])
        {
            parent[v]=pu;
        }
        else
        {
            rank[pu]++;
            parent[pu]=pv;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26,0),rank.resize(26,0);
        for(int i=0;i<26;i++)
        parent[i]=i;
        for(auto it:equations)
        {
            int pu = find(it[0]-'a');
            int pv = find(it[3]-'a');
            if(it[1]=='=')
            {
                union_by_rank(it[0]-'a',it[3]-'a');
            }
        }
        for(auto it:equations)
        {
            int pu = find(it[0]-'a');
            int pv = find(it[3]-'a');
            if(it[1]=='!')
            {
                if(pu==pv)
                return false;
            }
        }
        return true;
    }
};