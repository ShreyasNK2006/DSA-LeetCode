/*
 * Problem 1665: Minimum Initial Energy to Finish Tasks
 * URL     : https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
 * Solved  : 2026-05-12
 * Runtime : 1791 ms
 * Memory  : 493.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int curr=0,mine=0;
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),[] (vector<int> a,vector<int> b)
        {
            int diffa=a[1]-a[0];
            int diffb=b[1]-b[0];
            if(diffa!=diffb)
            return diffa>diffb;
            return a[0]>b[0];
        });
        mine=tasks[0][1];
        curr=mine-tasks[0][0];
        for(int i=1;i<n;i++)
        {
            if(curr>=tasks[i][1])
            curr-=tasks[i][0];
            else
            {
                mine+=(tasks[i][1]-curr);
                curr=tasks[i][1]-tasks[i][0];
            }
        }
        return mine;
    }
};