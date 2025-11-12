# Maximal Rectangle
Solved on 2025-10-31

class Solution {
public:
    int largestpsum(vector<int>& matrix)
    {
        stack<int> st;
        vector<int> prevsmallest(matrix.size()), nextsmallest(matrix.size());
        for(int i=0;i<matrix.size();i++)
        {
            while(!st.empty() && matrix[st.top()] >=matrix[i])
            {
                st.pop();
            }
            if(st.empty())
            prevsmallest[i]=0;
            else
            prevsmallest[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=matrix.size()-1;i>=0;i--)
        {
            while(!st.empty() && matrix[st.top()] >= matrix[i])
            st.pop();
            if(st.empty())
            nextsmallest[i]=matrix.size()-1;
            else
            nextsmallest[i]=st.top()-1;
            st.push(i);
        }
        int maxsum=0,sum=0;
        for(int i=0;i<matrix.size();i++)
        {
            sum=(matrix[i]*(nextsmallest[i]-prevsmallest[i]+1));
            maxsum=max(sum,maxsum);
        }
        return maxsum;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m= matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> prefsum(m,vector<int>(n,0));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<m;j++)
            {
                sum+=matrix[j][i]-'0';
                if(matrix[j][i]!='0')
                prefsum[j][i]=sum;
                else
                sum=0;
            }
        }
        int maxsum=0;
        for(int i=0;i<m;i++)
        {
            maxsum = max(maxsum,largestpsum(prefsum[i]));
        }
        return maxsum;
    }
};