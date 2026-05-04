/*
 * Problem 0962: Maximum Width Ramp
 * URL     : https://leetcode.com/problems/maximum-width-ramp/
 * Solved  : 2026-04-27
 * Runtime : 5 ms
 * Memory  : 48.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        int maxd=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty() || nums[i]<nums[st.top()])
            st.push(i);
        }
        for(int j=n-1;j>=0;j--)
        {
            while(!st.empty() && nums[j]>=nums[st.top()])
            {
                maxd=max(maxd,j-st.top());
                st.pop();
            }
        }
        return maxd;
    }
};