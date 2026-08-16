/*
 * Problem 1620: Coordinate With Maximum Network Quality
 * URL     : https://leetcode.com/problems/coordinate-with-maximum-network-quality/
 * Solved  : 2026-07-16
 * Runtime : 729 ms
 * Memory  : 183.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int x=0,y=0;
        int maxq=0,q=0;
        for(int i=0;i<=50;i++)
        {
            for(int j=0;j<=50;j++)
            {
                q=0;
                for(auto t:towers)
                {
                    int xc=t[0],yc=t[1],qc=t[2];
                    int d=(xc-i)*(xc-i)+(yc-j)*(yc-j);
                    if(d>radius*radius)
                    {
                        continue;
                    }
                    q=q+qc/(1+sqrt(d));
                }
                if(maxq<q)
                {
                    x=i;
                    y=j;
                    maxq=q;
                }
        }
        }
        return {x,y};
    }
};