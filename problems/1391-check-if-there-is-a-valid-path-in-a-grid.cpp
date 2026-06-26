/*
 * Problem 1391: Check if There is a Valid Path in a Grid
 * URL     : https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
 * Solved  : 2026-04-27
 * Runtime : 13 ms
 * Memory  : 59.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
    private:
    int m,n;
public:
    bool dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>>& visited,int prev)
    {
        if(i==m-1 && j==n-1)
        {
            if((prev==2 && (grid[i][j]==2||grid[i][j]==5||grid[i][j]==6)) ||(prev==1 && (grid[i][j]==1||grid[i][j]==3||grid[i][j]==5)) )
        return true;
        else
        return false;
        }
        if(i>=m||j>=n ||i<0 || j<0 || visited[i][j])
        return false;
        visited[i][j]=true;
        if(grid[i][j]==1 &&(prev==1||prev==-1||prev==0))
        {
            if(dfs(grid,i,j-1,visited,-1)||dfs(grid,i,j+1,visited,1))
            return true;
        }
        else if(grid[i][j]==2 && (prev==-2||prev==2||prev==0))
        {
            if(dfs(grid,i-1,j,visited,-2)||dfs(grid,i+1,j,visited,2))
            return true;
        }
        else if(grid[i][j]==3 && (prev==1||prev==0||prev==-2))
        {
            if((prev==-2 ||prev==0)&& dfs(grid,i,j-1,visited,-1))
            return true;
            else if((prev==1||prev==0)&& dfs(grid,i+1,j,visited,2))
            return true;
        }
        else if(grid[i][j]==4 && (prev==-2||prev==0||prev==-1))
        {
            if((prev==-2 ||prev==0)&& dfs(grid,i,j+1,visited,1))
            return true;
            else if((prev==-1||prev==0)&& dfs(grid,i+1,j,visited,2))
            return true;
        }
        else if(grid[i][j]==5 && (prev==1||prev==0||prev==2))
        {
            if((prev==2 ||prev==0)&& dfs(grid,i,j-1,visited,-1))
            return true;
            else if((prev==1||prev==0)&& dfs(grid,i-1,j,visited,-2))
            return true;
        }
        else if(grid[i][j]==6 && (prev==-1||prev==0||prev==2))
        {
            if((prev==2 ||prev==0)&& dfs(grid,i,j+1,visited,1))
            return true;
            else if((prev==-1||prev==0)&& dfs(grid,i-1,j,visited,-2))
            return true;
        }        
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m= grid.size(),n=grid[0].size();
        if(m-1==0 && n-1==0)
        return true;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(grid,0,0,visited,0);
    }
};