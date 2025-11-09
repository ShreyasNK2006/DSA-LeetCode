# Minimum Time to Make Rope Colorful
Solved on 2025-11-03

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0,maxtime=0;
        for(int i=0;i<colors.length()-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                time+=(neededTime[i]);
                maxtime = max(maxtime,neededTime[i]);
                maxtime = max(maxtime,neededTime[i+1]);
            }
            else
            {
                if(maxtime!=0)
                {
                    time+=neededTime[i];
                    time-=maxtime;
                    maxtime=0;
                }
            }
        }
        if(maxtime!=0)
                {
                    time+=neededTime[colors.length()-1];
                    time-=maxtime;
                }
        return time;
    }
};