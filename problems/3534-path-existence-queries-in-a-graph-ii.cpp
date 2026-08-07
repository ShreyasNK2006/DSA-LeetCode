/*
 * Problem 3534: Path Existence Queries in a Graph II
 * URL     : https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/
 * Solved  : 2026-07-11
 * Runtime : 500 ms
 * Memory  : 413.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n),gp(n);
        vector<pair<int,int>> wt(n);
        int m=queries.size();
        for(int i=0;i<n;i++)
        {
            wt[i]={nums[i],i};
        }
        sort(wt.begin(),wt.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[wt[i].second]=i;
        }
        for(int i=0;i<n;i++)
        gp[i]=i;
        for(int i=n-2;i>=0;i--)
        {
            if(wt[i+1].first-wt[i].first<=maxDiff)
            gp[i]=gp[i+1];
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(j<n-1 && wt[j+1].first-wt[i].first<=maxDiff)
            {
                j++;
            }
            parent[i]=j;
        }
        vector<vector<int>> jumps(n,vector<int>(20,0));
        for(int i=0;i<n;i++)
        jumps[i][0]=parent[i];
        for(int k=1;k<20;k++)
        {
            for(int i=0;i<n;i++)
            {
                jumps[i][k]=jumps[jumps[i][k-1]][k-1];
            }
        }
        vector<int> res(m,-1);
        for(int i=0;i<m;i++)
        {
            int x=mp[queries[i][0]],y=mp[queries[i][1]];
           // cout<<gp[x]<<" "<<gp[y]<<endl;
            if(gp[x]==gp[y])
            {
                int xc=min(x,y),yc=max(x,y);
                if(xc==yc)
                {
                    res[i]=0;
                    continue;
                }
                int c=0;
                for(int k=19;k>=0;k--)
                {
                    if(jumps[xc][k]<yc)
                    {
                        c+=(1<<k);
                        xc=jumps[xc][k];
                    }
                }
                res[i]=c+1;
            }
        }
        return res;
    }
};