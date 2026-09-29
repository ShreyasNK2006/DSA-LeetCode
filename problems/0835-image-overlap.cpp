/*
 * Problem 0835: Image Overlap
 * URL     : https://leetcode.com/problems/image-overlap/
 * Solved  : 2026-09-13
 * Runtime : 30 ms
 * Memory  : 12.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        // top left
        int mc=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c=0;
                for(int k=0;k<n-i;k++)
                {
                    int x =k;
                    for(int m = 0;m<n-j;m++)
                    {
                        int y=m ;
                        if(img1[k][m]==1 && img2[i+x][j+m]==1)
                        c++;
                        //cout<<img1[k][m]<<"a"<<img2[i+x][j+m]<<" ";
                    }
                    //cout<<endl;
                }
                mc=max(mc,c);
            }
        }
        // top right
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c=0;
                for(int k=0;k<n-i;k++)
                {
                    int x =k;
                    for(int m = n-1;m>=(n-1-j);m--)
                    {
                        int y =n-1-m;
                        if(img1[k][m]==1 && img2[i+x][j-y]==1)
                        c++;
                    }
                }
                mc=max(mc,c);
            }
        }
        //bottom right
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c=0;
                for(int k=n-1;k>=n-1-i;k--)
                {
                    int x =n-1-k;
                    for(int m = n-1;m>=n-1-j;m--)
                    {
                        int y =n-1-m;
                        if(img1[k][m]==1 && img2[i-x][j-y]==1)
                        c++;
                    }
                }
                mc=max(mc,c);
            }
        }
        //bottom left 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c=0;
                for(int k=n-1;k>=n-1-i;k--)
                {
                    int x =n-1-k;
                    for(int m = 0;m<n-j;m++)
                    {
                        if(img1[k][m]==1 && img2[i-x][j+m]==1)
                        c++;
                    }
                }
                mc=max(mc,c);
            }
        }
        return mc;
    }
};