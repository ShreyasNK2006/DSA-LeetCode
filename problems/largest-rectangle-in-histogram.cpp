/*
 * Problem: Largest Rectangle in Histogram
 * Solved on: 2025-10-30
 * Runtime: 17 ms
 * Memory: 85.8 MB
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> leftsmall(heights.size()),rightsmall(heights.size());
        for(int i=0;i<heights.size();i++)
        {

            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(st.empty())
            leftsmall[i]=0;
            else
                leftsmall[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            if(st.empty())
            rightsmall[i] = heights.size()-1;
            else 
                rightsmall[i]=st.top()-1;
            st.push(i);
        }
        int maxs=0;
        for(int i=0;i<heights.size();i++)
        {
            maxs = max(maxs,(rightsmall[i]-leftsmall[i]+1)*heights[i]);
        }
        return maxs;
    }
};