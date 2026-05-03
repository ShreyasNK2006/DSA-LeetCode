/*
 * Problem 3905: Multi Source Flood Fill
 * URL     : https://leetcode.com/problems/multi-source-flood-fill/
 * Solved  : 2026-04-30
 * Runtime : 120 ms
 * Memory  : 210.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> colorGrid(int m, int n, vector<vector<int>>& sources) {
        vector<vector<int>> res(m, vector<int>(n, 0)),
            visit(m, vector<int>(n, INT_MAX));
            queue<pair<int,int>> q;
        vector<pair<int, int>> dirn = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < sources.size(); i++) {
            visit[sources[i][0]][sources[i][1]] = 0;
            res[sources[i][0]][sources[i][1]] = sources[i][2];
            q.push({sources[i][0],sources[i][1]});
        }
        int t=0;
        while(!q.empty())
            {
                int s=q.size();
                t++;
                while(s)
                {
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    s--;
                    for(int i=0;i<4;i++)
                    {
                        int x=r+dirn[i].first;
                        int y= c+dirn[i].second;
                        if(x>=0 && y>=0 && x<m && y<n && visit[x][y]!=0 && visit[x][y]>=t)
                        {
                            if(visit[x][y]==t && res[r][c]>res[x][y])
                            {
                                res[x][y]=res[r][c];
                                q.push({x,y});
                            }
                            else if(visit[x][y]>t)
                            {
                                visit[x][y]=t;
                                res[x][y]=res[r][c];
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        return res;
    }
};