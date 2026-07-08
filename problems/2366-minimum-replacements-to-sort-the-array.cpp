/*
 * Problem 2366: Minimum Replacements to Sort the Array
 * URL     : https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
 * Solved  : 2026-06-09
 * Runtime : 5 ms
 * Memory  : 61.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long count=0;
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        st.push(nums[i]);
        int t=st.top();
        st.pop();
        while(!st.empty())
        {
            if(!st.empty() && st.top()>t)
            {
                int f=st.top()/t+(st.top()%t!=0?1:0);
                count=count+f-1;
                t=st.top()/f;              
            }
            else
            {
                t=st.top();
            }
            st.pop(); 
        }
        return count;
    }
};