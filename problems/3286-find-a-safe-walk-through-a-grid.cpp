/*
 * Problem 3286: Find a Safe Walk Through a Grid
 * URL     : https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
 * Solved  : 2026-07-02
 * Runtime : 12 ms
 * Memory  : 31.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0)),visited(m,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>> q;
        dp[0][0]=health-grid[0][0];
        q.push({dp[0][0],{0,0}});
        while(!q.empty())
        {
            int s= q.size();
            for(int i=0;i<s;i++)
            {
                int x=q.top().second.first;
                int y=q.top().second.second;
                int h=q.top().first;
                q.pop();
                if(visited[x][y])
                continue;
                visited[x][y]=1;
                if(x>0 && !visited[x-1][y])
                {
                    if(h-grid[x-1][y]>dp[x-1][y])
                    {
                        dp[x-1][y]=-grid[x-1][y]+h;
                        q.push({-grid[x-1][y]+h,{x-1,y}});
                    }
                }
                if(y>0 && !visited[x][y-1])
                {
                    if(-grid[x][y-1]+h>dp[x][y-1])
                    {
                        dp[x][y-1]=-grid[x][y-1]+h;
                        q.push({-grid[x][y-1]+h,{x,y-1}});
                    }
                }
                if(x<m-1 && !visited[x+1][y])
                {
                    if(-grid[x+1][y]+h>dp[x+1][y])
                    {
                        dp[x+1][y]=-grid[x+1][y]+h;
                        q.push({-grid[x+1][y]+h,{x+1,y}});
                    }
                }
                if(y<n-1 && !visited[x][y+1])
                {
                    if(-grid[x][y+1]+h>dp[x][y+1])
                    {
                        dp[x][y+1]=-grid[x][y+1]+h;
                        q.push({-grid[x][y+1]+h,{x,y+1}});
                    }
                }

            }
        }
        //cout<<dp[m-1][n-1];
        return dp[m-1][n-1]>0?true:false;
    }
};