/*
 * Problem 2812: Find the Safest Path in a Grid
 * URL     : https://leetcode.com/problems/find-the-safest-path-in-a-grid/
 * Solved  : 2026-07-06
 * Runtime : 454 ms
 * Memory  : 248.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool valid(vector<vector<int>>&grid,int &n,int v)
    {
        vector<vector<int>> visited(n,vector<int>(n,0));
        if(grid[0][0]<v)
        return false;
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==n-1 && y==n-1)
            return true;
            if(x>0)
                {
                    if(!visited[x-1][y] && grid[x-1][y]>=v)
                    {
                        q.push({x-1,y});
                        visited[x-1][y]=1;
                    }
                    
                }
                if(x<n-1)
                {
                    if(!visited[x+1][y] && grid[x+1][y]>=v)
                    {
                        q.push({x+1,y});
                        visited[x+1][y]=1;
                    }
                }
                if(y>0)
                {
                    if(!visited[x][y-1] && grid[x][y-1]>=v)
                    {
                        q.push({x,y-1});
                        visited[x][y-1]=1;
                    }
                }
                if(y<n-1)
                {
                    if(!visited[x][y+1] && grid[x][y+1]>=v)
                    {
                        q.push({x,y+1});
                        visited[x][y+1]=1;
                    }
                }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    grid[i][j]=0;
                    q.push({i,j});
                }
                else
                grid[i][j]=-1;
            }
        }
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                int val=grid[x][y];
                if(x>0)
                {
                    if(grid[x-1][y]==-1)
                    {
                        q.push({x-1,y});
                        grid[x-1][y]=1+val;
                    }
                }
                if(x<n-1)
                {
                    if(grid[x+1][y]==-1)
                    {
                        q.push({x+1,y});
                        grid[x+1][y]=1+val;
                    }
                }
                if(y>0)
                {
                    if(grid[x][y-1]==-1)
                    {
                        q.push({x,y-1});
                        grid[x][y-1]=1+val;
                    }
                }
                if(y<n-1)
                {
                    if(grid[x][y+1]==-1)
                    {
                        q.push({x,y+1});
                        grid[x][y+1]=1+val;
                    }
                }
            }
        }
        int l=0;
        int h=n*2-2;
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(valid(grid,n,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
        }
        return ans;
    }
};