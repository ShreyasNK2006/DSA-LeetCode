/*
 * Problem 0962: Maximum Width Ramp
 * URL     : https://leetcode.com/problems/maximum-width-ramp/
 * Solved  : 2026-04-27
 * Runtime : 5 ms
 * Memory  : 48.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        int maxd=0;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty() || nums[st.top()]<nums[i])
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[i]<=nums[st.top()])
            {
                maxd=max(maxd,st.top()-i);
                st.pop();
            }
        }
        return maxd;
    }
};