/*
 * Problem 3951: Minimum Energy to Maintain Brightness
 * URL     : https://leetcode.com/problems/minimum-energy-to-maintain-brightness/
 * Solved  : 2026-06-06
 * Runtime : 85 ms
 * Memory  : 204.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long ans=0;
        long long minn=brightness/3;
        if(brightness%3!=0)
            minn+=1;
        sort(intervals.begin(),intervals.end());
        stack<int> st;
        ans=minn*(intervals[0][1]-intervals[0][0]+1);
        st.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++)
            {
                if(intervals[i][0]>st.top())
                {
                    ans=ans+minn*(intervals[i][1]-intervals[i][0]+1);
                    st.pop();
                    st.push(intervals[i][1]);
                }
                else
                {
                    ans=ans+minn*max(0,intervals[i][1]-st.top());
                    if(intervals[i][1]>st.top())
                    {
                        st.pop();
                        st.push(intervals[i][1]);
                    }
                }
            }
        return ans;
        
    }
};