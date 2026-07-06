/*
 * Problem 1840: Maximum Building Height
 * URL     : https://leetcode.com/problems/maximum-building-height/
 * Solved  : 2026-06-20
 * Runtime : 1374 ms
 * Memory  : 106.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(),restrictions.end());
        restrictions.insert(restrictions.begin(),{1,0});
        int r=restrictions.size();
        int maxh=0;
        for(int i=0;i<r;i++)
        {
            restrictions[i][1]=min(restrictions[i][0]-1,restrictions[i][1]);
        }
        for(int i=0;i<r-1;i++)
        {
            if(restrictions[i+1][1]-restrictions[i][1]<=restrictions[i+1][0]-restrictions[i][0])
            continue;
            else
            restrictions[i+1][1]=restrictions[i][1]+restrictions[i+1][0]-restrictions[i][0];
        }
        for(int i=r-2;i>=0;i--)
        {
            if(restrictions[i][1]-restrictions[i+1][1]<=restrictions[i+1][0]-restrictions[i][0])
            continue;
            else
            restrictions[i][1]=restrictions[i+1][1]+restrictions[i+1][0]-restrictions[i][0];
        }
        /*for(int i=r-2;i>=0;i--)
        {
            if(abs(restrictions[i][1]-restrictions[i+1][1])<(restrictions[i+1][0]-restrictions[i][0]))
            continue;
            else
            {
                int sign= restrictions[i][1]-restrictions[i+1][1];
                if(sign<0)
                {
                    restrictions[i+1][1]=restrictions[i][1]+restrictions[i+1][0]-restrictions[i][0];
                }
                else
                {
                    restrictions[i+1][1]=restrictions[i][1]-restrictions[i+1][0]+restrictions[i][0];
                }
            }
        }*/
        for(int i=0;i<r-1;i++)
        {
            maxh=max(maxh,(restrictions[i][1]+restrictions[i+1][1]+restrictions[i+1][0]-restrictions[i][0])/2);
            cout<<restrictions[i][1]<<" "<<restrictions[i+1][1]<<endl;
        }
        if(restrictions[r-1][0]!=n)
        maxh=max(maxh,restrictions[r-1][1]+(n-restrictions[r-1][0]));
        return maxh;
    }
};