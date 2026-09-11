/*
 * Problem 4024: Nearest Available Drone
 * URL     : https://leetcode.com/problems/nearest-available-drone/
 * Solved  : 2026-08-16
 * Runtime : 0 ms
 * Memory  : 56.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int dist =INT_MAX, ind=-1;
        int i=0;
        for(auto it:drones)
            {
                int d = abs(it[0]-target[0])+abs(it[1]-target[1]);
                if(d<=it[2])
                {
                    if(dist>d)
                    {
                        dist=d;
                        ind=i;
                    }
                }
                i++;
            }
        return ind;
    }
};