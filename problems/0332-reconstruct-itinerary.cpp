/*
 * Problem 0332: Reconstruct Itinerary
 * URL     : https://leetcode.com/problems/reconstruct-itinerary/
 * Solved  : 2026-09-25
 * Runtime : 15 ms
 * Memory  : 21.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> mp;
        unordered_map<string,int> ind;
        for(auto it:tickets)
        {
            mp[it[0]].push_back(it[1]);
            ind[it[0]]=0;
        }
        for(auto it:mp)
        {
            sort(mp[it.first].begin(),mp[it.first].end());
        }
        vector<string> res;
        stack<string> st;
        st.push("JFK");
        while(!st.empty())
        {
            if(mp[st.top()].size()>ind[st.top()])
            {
                ind[st.top()]++;
                st.push(mp[st.top()][ind[st.top()]-1]);
            }
            else
            {
                res.push_back(st.top());
                st.pop();
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};