/*
 * Problem 1288: Remove Covered Intervals
 * URL     : https://leetcode.com/problems/remove-covered-intervals/
 * Solved  : 2026-07-06
 * Runtime : 78 ms
 * Memory  : 34 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int c=0;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            if(a[0]==b[0])
            return a[1]>b[1];
            else
            return a[0]<b[0];          
        });
        int n=intervals.size();
        vector<int> exist(n,1);
        for(int i=0;i<n;i++)
        {
            if(exist[i])
            {
                c++;
                for(int j=i+1;j<n;j++)
                {
                    if(intervals[j][1]<=intervals[i][1])
                    exist[j]=0;
                }
            }
        }
        return c;
    }
};