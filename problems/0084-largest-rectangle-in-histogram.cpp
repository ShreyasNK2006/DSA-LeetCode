/*
 * Problem 0084: Largest Rectangle in Histogram
 * URL     : https://leetcode.com/problems/largest-rectangle-in-histogram/
 * Solved  : 2026-04-24
 * Runtime : 1371 ms
 * Memory  : 89.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int largest=0;
        vector<int> rightbound(n),leftbound(n);
        st.push(0);
        for(int i=1;i<n;i++)
        {
            if(st.empty() || heights[st.top()]<=heights[i] )
            st.push(i);
            else
            {
                while(!st.empty() && heights[st.top()]>heights[i])
                {
                    rightbound[st.top()]=i-1;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty())
        {
            rightbound[st.top()]=n-1;
            st.pop();
        }
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(st.empty() || heights[st.top()]<=heights[i])
            st.push(i);
            else
            {
                while(!st.empty() && heights[st.top()]>heights[i])
                {
                    leftbound[st.top()]=i+1;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty())
        {
            leftbound[st.top()]=0;
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            largest=max(largest,(rightbound[i]-leftbound[i]+1)*heights[i]);
            cout<<largest<<endl;
        }
        return largest;
    }
};