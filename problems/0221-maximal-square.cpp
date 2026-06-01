/*
 * Problem 0221: Maximal Square
 * URL     : https://leetcode.com/problems/maximal-square/
 * Solved  : 2026-05-16
 * Runtime : 35 ms
 * Memory  : 30.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> prev(n+1,0);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n+1,0);
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    curr[j+1]=1+prev[j+1];
                }
            }
            prev=curr;
            for(int j=0;j<n;j++)
            {
                int k=curr[j+1];
                int l=curr[j+1];
                int s=l;
                while(k && s>l-k && j+1+l-k<=n)
                {
                    s=min(s,curr[j+1+l-k]);
                    k--;
                }
                if(l-k>=s)
                ans=max(ans,s*s);
            }     
        }
        return ans;
    }
};