/*
 * Problem 3964: Minimum Lights to Illuminate a Road
 * URL     : https://leetcode.com/problems/minimum-lights-to-illuminate-a-road/
 * Solved  : 2026-06-23
 * Runtime : 21 ms
 * Memory  : 277.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minLights(vector<int>& lights) {
        int nxt=0;
        int n=lights.size();
        vector<int> lited(n,0);
        for(int i=0;i<n;i++)
        {
            if(lights[i]!=0)
            {
                lited[i]=1;
            }
            if(nxt<=lights[i] && lights[i]!=0)
            nxt=lights[i];
            else if(nxt!=0)
            {
                nxt--;
                lited[i]=1;
            }
        }
        nxt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(lights[i]!=0)
            {
                lited[i]=1;
            }
            if(nxt<=lights[i] && lights[i]!=0)
            nxt=lights[i];
            else if(nxt!=0)
            {
                nxt--;
                lited[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(lited[i]==0)
            {
                if(i>0 && lited[i-1]==2)
                {
                    lited[i]=1;
                }
                else if(i<n-1 && lited[i+1]==0)
                {
                    ans++;
                    lited[i]=1;
                    lited[i+1]=2;
                }
                else if(i<n-1 && lited[i+1]==1)
                {
                    ans++;
                    lited[i]=2;
                }
                else if(i==0 || i==n-1)
                    ans++;
            }
        }
        return ans;
    }
};