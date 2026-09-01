/*
 * Problem 4001: Aggregate Two Time Series
 * URL     : https://leetcode.com/problems/aggregate-two-time-series/
 * Solved  : 2026-08-14
 * Runtime : 761 ms
 * Memory  : 468.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        
        vector<vector<int>> res;
        map<int,int> mp1,mp2;
        int maxb=0;
        unordered_set<int> st;
        for(auto it:series1)
            {
                maxb=max(maxb,it[0]);
                mp1[it[0]]=it[1];
                st.insert(it[0]);
            }
        for(auto it:series2)
            {
                maxb=max(maxb,it[0]);
                mp2[it[0]]=it[1];
                st.insert(it[0]);
            }
        for(auto i:st)
            {
                auto it1 = mp1.lower_bound(i);
                auto it2 = mp2.lower_bound(i);
                int val =0;
                if(it1!=mp1.end())
                    val+=it1->second;
                if(it2!=mp2.end())
                    val+=it2->second;
                res.push_back({i,val});
            }
        sort(res.begin(),res.end());
        return res;
    }
};