/*
 * Problem 1727: Largest Submatrix With Rearrangements
 * URL     : https://leetcode.com/problems/largest-submatrix-with-rearrangements/
 * Solved  : 2026-03-17
 * Runtime : 119 ms
 * Memory  : 115.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> h(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix[0].size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                h[j][i]=matrix[j][i];
                if(j>0 && matrix[j][i]==1)
                h[j][i]+=h[j-1][i];
            }
        }
        int ans=INT_MIN;
        int m=INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            vector<int> temp;
            m=INT_MAX;
            for(int j=0;j<matrix[0].size();j++)
            temp.push_back(h[i][j]);
            sort(temp.rbegin(),temp.rend());
            for(int j=0;j<matrix[0].size();j++)
            {
                m=min(m,temp[j]);
                ans=max(ans,(j+1)*m);
            }
        }
        return ans;
    }
};