/*
 * Problem 1235: Maximum Profit in Job Scheduling
 * URL     : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
 * Solved  : 2026-08-10
 * Runtime : 227 ms
 * Memory  : 117.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> inp;
        int n=0;
        for(int i=0;i<startTime.size();i++)
        {
            inp.push_back({endTime[i],startTime[i],profit[i]});
            n=max(n,endTime[i]);
        }
        sort(inp.begin(),inp.end());
        map<int,int>mp;
        mp[0]=0;
        int et=0;
        for(auto it: inp)
        {
            auto it2 = mp.upper_bound(it[1]);
            auto it3 = mp.upper_bound(it[0]);
            if(it3!=mp.begin())
            {
                it3--;
                mp[it[0]]=max(mp[it[0]],it3->second);
            }
            if(it2!=mp.begin())
            {
                it2--;
                mp[it[0]]=max(mp[it[0]],it2->second+it[2]);
            }
        }
        return mp[n];
    }
};