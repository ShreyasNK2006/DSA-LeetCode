/*
 * Problem 1202: Smallest String With Swaps
 * URL     : https://leetcode.com/problems/smallest-string-with-swaps/
 * Solved  : 2026-08-09
 * Runtime : 47 ms
 * Memory  : 62.7 MB
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
    void union_rank(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if(rank[pu]>rank[pv])
        {
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu])
        {
            parent[pu]=pv;
        }
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n= s.size();
        parent.resize(n,0),rank.resize(n,0);
        for(int i=0;i<s.size();i++)
        {
            parent[i]=i;
        }
        for(auto it:pairs)
        {
            int c1 = it[0];
            int c2 = it[1];
            union_rank(c1,c2);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<s.size();i++)
        {
            int p = find(i);
            mp[p].push_back(i);
        }
        string res = s;
        for(auto it: mp)
        {
            vector<int> temp(26,0);
            for(auto c: it.second)
            {
                temp[s[c]-'a']++;
            }
            int l=0;
            for(auto c:it.second)
            {
                while(temp[l]==0)
                {
                    l++;
                }
                res[c]=('a'+l);
                temp[l]--;
            }
        }
        return res;
    }
};