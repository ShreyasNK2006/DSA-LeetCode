/*
 * Problem 4026: Maximum Gap Between Stations
 * URL     : https://leetcode.com/problems/maximum-gap-between-stations/
 * Solved  : 2026-08-16
 * Runtime : 48 ms
 * Memory  : 58.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximumGap(string skill, string station) {
        int maxg=0;
        int n=skill.size(),m=station.size();
        int j=0;
        vector<int> pos(n+1,0);
        for(int i=0;i<n;i++)
            {
                while(j<m && skill[i]!=station[j])
                    j++;
                pos[i]=j;
                if(i>0)
                    maxg=max(maxg,pos[i]-pos[i-1]);
                j++;
            }
        int st=m-1;
        for(int i=n-1;i>=1;i--)
            {
                while(st>=pos[i])
                    {
                        if(station[st]==skill[i])
                        {
                            pos[i]=st;
                            st--;
                            break;
                        }
                        st--;
                    }
                maxg=max(maxg,pos[i]-pos[i-1]);
            }
        return maxg;
    }
};