/*
 * Problem 3635: Earliest Finish Time for Land and Water Rides II
 * URL     : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/
 * Solved  : 2026-06-02
 * Runtime : 343 ms
 * Memory  : 306.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n1=landDuration.size(),n2=waterDuration.size();
        vector<vector<int>> finishtimew(n2, vector<int>(2)),finishtimel(n1,vector<int>(2));
        for(int i =0;i<n1;i++)
        {
            finishtimel[i]={landDuration[i]+landStartTime[i], landStartTime [i]};
        }
        for(int i =0;i<n2;i++)
        {
            finishtimew[i]={waterDuration[i]+waterStartTime[i], waterStartTime [i]};
        }
        sort(finishtimew.begin(), finishtimew.end());
        sort(finishtimel.begin(), finishtimel.end());
        // case 1
        int mintime=INT_MAX,temp1;
        temp1=INT_MAX;
        //bool cond1=false,cond2=false;
        for(int i=0;i<n2;i++)
        {
            if(finishtimew[i][1]>=finishtimel[0][0])
            {
                temp1=min(temp1,finishtimew[i][0]);
                break;
            }
            else
            {
                temp1=min(temp1,finishtimel[0][0]+finishtimew[i][0]-finishtimew[i][1]);
            }
        }
        //case 2
        int temp2=INT_MAX;
        for(int i=0;i<n1;i++)
        {
            if(finishtimel[i][1]>=finishtimew[0][0])
            {
                temp2=min(temp2,finishtimel[i][0]);
                break;
            }
            else
            {
                temp2=min(temp2,finishtimew[0][0]+finishtimel[i][0]-finishtimel[i][1]);
            }
        }
        mintime=min(temp2,temp1);
        return mintime;
    }
};