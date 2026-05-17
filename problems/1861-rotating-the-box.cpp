/*
 * Problem 1861: Rotating the Box
 * URL     : https://leetcode.com/problems/rotating-the-box/
 * Solved  : 2026-05-06
 * Runtime : 16 ms
 * Memory  : 63.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<char>> res(n,vector<char>(m));
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='*')
                {
                    temp[j]=-1;
                    if(c!=0)
                    temp[j-1]=c;
                    c=0;
                }
                else if(grid[i][j]=='#')
                c++;
            }
            if(grid[i][n-1]!='*')
            temp[n-1]=c;
            for(int j=n-1;j>=0;j--)
            {
                if(temp[j]==-1)
                res[j][m-1-i]='*';
                else if(temp[j]>0)
                {
                    int k=j;
                    while(temp[j]--)
                    {
                        res[k][m-1-i]='#';
                        if(temp[j])
                        k--;
                    }
                    j=k;
                }
                else
                {
                    res[j][m-1-i]='.';
                }
            }
        }
        return res;
    }
};