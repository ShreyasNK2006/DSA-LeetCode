/*
 * Problem 3873: Maximum Points Activated with One Addition
 * URL     : https://leetcode.com/problems/maximum-points-activated-with-one-addition/
 * Solved  : 2026-03-15
 * Runtime : 224 ms
 * Memory  : 300.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> parent,sz;
    int find(int i)
    {
        if(i==parent[i])
        return i;
        else
        return parent[i]=find(parent[i]);
    }
    void unite(int u,int v)
    {
        int upu=find(u),upv=find(v);
        if(upu==upv)
        return;
        else if(sz[upu]>sz[upv])
        {
            parent[upv]=upu;
            sz[upu]+=sz[upv];
        }
        else if(sz[upv]>sz[upu])
        {
            parent[upu]=upv;
            sz[upv]+=sz[upu];
        }
        else
        {
            parent[upv]=upu;
            sz[upu]+=sz[upv];
        }
    }
    int maxActivated(vector<vector<int>>& points) {
        int n =points.size();
        parent.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            sz[i]=1;
        }
        unordered_map<int,int> x,y;
        for(int i=0;i<n;i++)
        {
            if(x.count(points[i][0]))
            unite(i,x[points[i][0]]);
            else 
            x[points[i][0]]=i;
            if(y.count(points[i][1]))
            unite(i,y[points[i][1]]);
            else 
            y[points[i][1]]=i;
        }
        int mp1=0,mp2=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                if(sz[i]>mp1)
                {
                    mp2=mp1;
                    mp1=sz[i];
                }
                else if(sz[i]>mp2)
                {
                    mp2=sz[i];
                }
            }
        }
        return mp1 + mp2 +1;
    }
};