/*
 * Problem 4025: Minimize the Maximum Waiting Time at Synchronized Traffic Lights
 * URL     : https://leetcode.com/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/
 * Solved  : 2026-08-16
 * Runtime : 63 ms
 * Memory  : 193.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& at1) {
        vector<int> at=at1;
        for(int i=0;i<at.size();i++)
            {
                at[i]=at[i]%period;
            }
        int maxwait=0;
        set<int> st;
        for(auto it:lights)
            {
                st.insert(it);
            }
        for(auto it:at)
            {
                auto it2 = st.upper_bound(it);
                if(it2!=st.end())
                    continue;
                else
                {
                    maxwait=max(maxwait,period-it);
                }
            }
        return maxwait;
    }
};