/*
 * Problem 4016: Maximum Area of Two Non-Overlapping Square Submatrices
 * URL     : https://leetcode.com/problems/maximum-area-of-two-non-overlapping-square-submatrices/
 * Solved  : 2026-08-11
 * Runtime : 97 ms
 * Memory  : 139.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sq1(m,vector<int> (n,0)),sq2(m,vector<int> (n,0));
        vector<int> top(m,0),bot(m,0),lft(n,0),rit(n,0);
        sq1=mat;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] && !(i==0||j==0))
                {
                    int mins = min({sq1[i][j-1],sq1[i-1][j],sq1[i-1][j-1]});
                    sq1[i][j]=1+mins;
                }
                top[i]=max(top[i],sq1[i][j]);
                lft[j]=max(lft[j],sq1[i][j]);
            }
        }
        for(int i=1;i<m;i++)
        top[i]=max(top[i],top[i-1]);
        for(int i=1;i<n;i++)
        lft[i]=max(lft[i],lft[i-1]);
        sq2=mat;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(mat[i][j] && !(i==m-1||j==n-1))
                {
                    int mins = min({sq2[i][j+1],sq2[i+1][j],sq2[i+1][j+1]});
                    sq2[i][j]=1+mins;
                }
                bot[i]=max(bot[i],sq2[i][j]);
                rit[j]=max(rit[j],sq2[i][j]);
            }
        }
        for(int i=m-2;i>=0;i--)
        {
            bot[i]=max(bot[i],bot[i+1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rit[i]=max(rit[i],rit[i+1]);
        }
        int maxs=0;
        for(int i=0;i<m-1;i++)
        {
            maxs= max(maxs,min(top[i],bot[i+1]));
        }
        for(int i=0;i<n-1;i++)
        {
            maxs= max(maxs,min(lft[i],rit[i+1]));
        }
        return maxs*maxs;
    }
};