/*
 * Problem 0874: Walking Robot Simulation
 * URL     : https://leetcode.com/problems/walking-robot-simulation/
 * Solved  : 2026-04-06
 * Runtime : 21 ms
 * Memory  : 37.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int maxd=0;
        int x=0,y=0;
        int n=obstacles.size();
        int dirn=0;
        set<pair<int,int>> st;
        int m=commands.size();
        for(int i=0;i<n;i++)
        st.insert({obstacles[i][0],obstacles[i][1]});
        for(int i=0;i<m;i++)
        {
            int tempx=x,tempy=y;
            if(commands[i]==-1)
            {
                dirn=(dirn+1)%4;
            }
            else if(commands[i]==-2)
            {
                dirn=((4+dirn-1)%4);
            }
            else
            {
                while(commands[i])
                {
                    if(dirn==0)
                    tempy+=1;
                    else if(dirn==3)
                    tempx-=1;
                    else if(dirn==2)
                    tempy-=1;
                    else
                    tempx+=1;
                    if(st.find({tempx,tempy})==st.end())
                    {
                        x=tempx;
                        y=tempy;
                    }
                    commands[i]--;
                    tempx=x;
                    tempy=y;
                }
            }
            maxd=max(maxd,x*x + y*y);
        }
        return maxd;
    }
};