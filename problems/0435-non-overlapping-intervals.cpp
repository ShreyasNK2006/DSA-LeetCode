/*
 * Problem 0435: Non-overlapping Intervals
 * URL     : https://leetcode.com/problems/non-overlapping-intervals/
 * Solved  : 2026-07-26
 * Runtime : 59 ms
 * Memory  : 93.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int x= intervals[0][0];
        int y =intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<y && intervals[i][0]>=x)
            {
                count++;
                if(intervals[i][1]>y)
                continue;
                else
                {
                    x = intervals[i][0];
                    y = intervals[i][1];
                }
            }
            else
            {
                x = intervals[i][0];
                y = intervals[i][1];
            }
        }
        return count;
    }
};