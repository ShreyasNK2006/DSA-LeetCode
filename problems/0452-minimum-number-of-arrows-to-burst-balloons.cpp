/*
 * Problem 0452: Minimum Number of Arrows to Burst Balloons
 * URL     : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * Solved  : 2026-07-26
 * Runtime : 57 ms
 * Memory  : 93.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int count=1;
        int x= points[0][0],y=points[0][1];
        for(int i=1;i<n;i++)
        {
            if(points[i][0]<=y && points[i][0]>=x)
            {
                y=min(y,points[i][1]);
            }
            else
            {
                count++;
                x=points[i][0];
                y=points[i][1];
            }
        }
        return count;
    }
};