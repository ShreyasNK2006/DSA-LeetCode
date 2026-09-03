/*
 * Problem 1254: Number of Closed Islands
 * URL     : https://leetcode.com/problems/number-of-closed-islands/
 * Solved  : 2026-08-02
 * Runtime : 11 ms
 * Memory  : 18.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(grid[i][j]==0)
                q.push({i,j});
            }
        }
        int c=0;
        while(!q.empty())
        {
            int x = q.front().first,y = q.front().second;
            q.pop();
            if(visited[x][y])
            continue;
            bool cond=true;
            queue<pair<int,int>> q2;
            q2.push({x,y});
            while(!q2.empty())
            {
                int x1 = q2.front().first, y1 = q2.front().second;
                visited[x1][y1]=true;
                q2.pop();
                if(x1>0 && grid[x1-1][y1]==0 && !visited[x1-1][y1])
                {
                    q2.push({x1-1,y1});
                    visited[x1-1][y1]=true;
                    if(x1-1==0)
                    {   
                        cond=false;
                    }
                }
                if(x1<m-1 && grid[x1+1][y1]==0 && !visited[x1+1][y1])
                {
                    q2.push({x1+1,y1});
                    visited[x1+1][y1]=true;
                    if(x1+1==m-1)
                    {   
                        cond=false;
                    }
                }
                if(y1>0 && grid[x1][y1-1]==0 &&  !visited[x1][y1-1])
                {
                    q2.push({x1,y1-1});
                    visited[x1][y1-1]=true;
                    if(y1-1==0)
                    {   
                        cond=false;
                    }
                }
                if(y1<n-1 && grid[x1][y1+1]==0 && !visited[x1][y1+1])
                {
                    q2.push({x1,y1+1});
                    visited[x1][y1+1]=true;
                    if(y1+1==n-1)
                    {   
                        cond=false;
                    }
                }
            }
            if(cond)
            c++;
        }
        return c;
    }
};