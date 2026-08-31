/*
 * Problem 1926: Nearest Exit from Entrance in Maze
 * URL     : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 * Solved  : 2026-07-31
 * Runtime : 7 ms
 * Memory  : 39.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int c=0;
        q.push({entrance[0],entrance[1]});
        bool found=false;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(visited[x][y])
                continue;
                visited[x][y]=true;
                if((x==0 || x==m-1|| y==0 || y==n-1)&&(!(x==entrance[0] && y==entrance[1])))
                {
                    found=true;
                    break;
                }
                if(x>0 && !visited[x-1][y] && maze[x-1][y]=='.')
                {
                    q.push({x-1,y});
                }
                if(y>0 && !visited[x][y-1] && maze[x][y-1]=='.')
                {
                    q.push({x,y-1});
                }
                if(x<m-1 && !visited[x+1][y] && maze[x+1][y]=='.')
                {
                    q.push({x+1,y});
                }
                if(y<n-1 && !visited[x][y+1] && maze[x][y+1]=='.')
                {
                    q.push({x,y+1});
                }
            }
            if(found)
            break;
            c++;
        }
        return found?c:-1;
    }
};