/*
 * Problem 1401: Circle and Rectangle Overlapping
 * URL     : https://leetcode.com/problems/circle-and-rectangle-overlapping/
 * Solved  : 2026-09-19
 * Runtime : 0 ms
 * Memory  : 7.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //double cd = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        double maxd =0;
        if(x1> xCenter || x2<xCenter)
        maxd += min(pow(x1-xCenter,2),pow(x2-xCenter,2));
        if(y1> yCenter || y2<yCenter)
        maxd += min(pow(y1-yCenter,2),pow(y2-yCenter,2));
        return maxd<= r*r;

    }
};