/*
 * Problem 0934: Shortest Bridge
 * URL     : https://leetcode.com/problems/shortest-bridge/
 * Solved  : 2026-07-30
 * Runtime : 57 ms
 * Memory  : 28.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> grid2(n,vector<int>(n,0)),visited(n,vector<int>(n,0)),dist(n,vector<int>(n,INT_MAX));
        grid2=grid;
        int stx=-1,sty=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    stx=i;
                    sty=j;
                    break;
                }
            }
            if(stx!=-1)
            break;
        }
        queue<pair<int,int>> q;
        q.push({stx,sty});
        grid2[stx][sty]=2;
        while(!q.empty())
        {
            int s =q.size();
            for(int i=0;i<s;i++)
            {
                int x= q.front().first;
                int y= q.front().second;
                q.pop();
                dist[x][y]=0;
                if(visited[x][y])
                continue;
                visited[x][y]=true;
                if(x>0 && !visited[x-1][y] && grid2[x-1][y]==1)
                {
                    grid2[x-1][y]=2;
                    q.push({x-1,y});
                }
                if(y>0 && !visited[x][y-1] && grid2[x][y-1]==1)
                {
                    grid2[x][y-1]=2;
                    q.push({x,y-1});
                }
                if(x<n-1 && !visited[x+1][y] && grid2[x+1][y]==1)
                {
                    grid2[x+1][y]=2;
                    q.push({x+1,y});
                }
                if(y<n-1 && !visited[x][y+1] && grid2[x][y+1]==1)
                {
                    grid2[x][y+1]=2;
                    q.push({x,y+1});
                }
            }
        }
        vector<vector<int>> visited2(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int ans=INT_MAX;
        pq.push({0,{stx,sty}});
        while(!pq.empty())
        {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            if(grid2[x][y]==1)
            ans=min(ans,dist[x][y]);
            pq.pop();
            if(visited2[x][y])
            continue;
            visited2[x][y]=true;
            if(x>0 && !visited2[x-1][y])
                {
                    if(grid2[x-1][y]==2)
                    pq.push({0,{x-1,y}});
                    else if(dist[x-1][y]>d+1)
                    {
                        pq.push({d+1,{x-1,y}});
                        dist[x-1][y]=d+1;
                    }
                }
                if(y>0 && !visited2[x][y-1])
                {
                    if(grid2[x][y-1]==2)
                    pq.push({0,{x,y-1}});
                    else if(dist[x][y-1]>d+1)
                    {
                        pq.push({d+1,{x,y-1}});
                        dist[x][y-1]=d+1;
                    }
                }
                if(x<n-1 && !visited2[x+1][y])
                {
                    if(grid2[x+1][y]==2)
                    pq.push({0,{x+1,y}});
                    else if(dist[x+1][y]>d+1)
                    {
                        pq.push({d+1,{x+1,y}});
                        dist[x+1][y]=d+1;
                    }
                }
                if(y<n-1 && !visited2[x][y+1])
                {
                    if(grid2[x][y+1]==2)
                    pq.push({0,{x,y+1}});
                    else if(dist[x][y+1]>d+1)
                    {
                        pq.push({d+1,{x,y+1}});
                        dist[x][y+1]=d+1;
                    }
                }
        }
        return ans-1;
    }
};