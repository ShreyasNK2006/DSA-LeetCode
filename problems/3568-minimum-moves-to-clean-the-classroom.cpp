/*
 * Problem 3568: Minimum Moves to Clean the Classroom
 * URL     : https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
 * Solved  : 2026-09-03
 * Runtime : 233 ms
 * Memory  : 154.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size(),n=classroom[0].size();
        vector<vector<int>> id(m,vector<int>(n,0));
        int sx=0,sy=0;
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(classroom[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                if(classroom[i][j]=='L')
                {
                    id[i][j]=1<<count;
                    count++;
                }
            }
        }
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};
        vector<vector<vector<int>>> eng(m,vector<vector<int>>(n,vector<int>(1<<count,-1)));
        struct t{
            int x,y,curr,mask,steps;
        };
        queue<t>q;
        q.push({sx,sy,energy,0,0});
        eng[sx][sy][0]=energy;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int cx = q.front().x;
                int cy = q.front().y;
                int ce = q.front().curr;
                int mk = q.front().mask;
                int stp = q.front().steps;
                if(mk==((1<<count)-1))
                    return stp;
                q.pop();
                if(ce==0)
                continue;
                for(int j=0;j<4;j++)
                {
                    int nx = cx+dx[j];
                    int ny = cy+dy[j];
                    if(nx<0 || nx==m ||  ny<0 || ny==n || classroom[nx][ny]=='X')
                    continue;
                    int ne = ce;
                    ne = classroom[nx][ny]=='R'?energy:ce-1;
                    int nmk = mk|id[nx][ny];
                    if(ne>eng[nx][ny][nmk])
                    {
                        eng[nx][ny][nmk]=ne;
                        q.push({nx,ny,ne,nmk,stp+1});
                    }
                }
            }
        }
        return -1;
    }
};