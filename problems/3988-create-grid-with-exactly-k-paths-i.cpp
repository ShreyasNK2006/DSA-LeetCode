/*
 * Problem 3988: Create Grid With Exactly K Paths I
 * URL     : https://leetcode.com/problems/create-grid-with-exactly-k-paths-i/
 * Solved  : 2026-07-12
 * Runtime : 0 ms
 * Memory  : 9.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    
    vector<string> createGrid(int m, int n, int k) {
        if((k>1 && (min(m,n)<2 ||( max(m,n)<min(3,k))))||(k==4 && (min(m,n)<3 && max(m,n)==3)))
        return { };
        string temp;
        for(int i=0;i<n;i++)
            temp.push_back('#');
        vector<string> res(m,temp);
        res[0][0]='.';
        res[m-1][n-1]='.';
        if(k==1)
        {
            for(int i=0;i<m;i++)
            res[i][0]='.';
            for(int i=0;i<n;i++)
            res[m-1][i]='.';
        }
        if(k==2)
        {
            res[1][0]='.';
            for(int i=0;i<m;i++)
            res[i][1]='.';
            for(int i=1;i<n;i++)
            res[m-1][i]='.';
        }
        if(k==3)
        {
            if(m>2)
            {
                res[1][0]='.';
                res[2][0]='.';
                for(int i=0;i<m;i++)
                    res[i][1]='.';
                for(int i=1;i<n;i++)
                    res[m-1][i]='.';
            }
            else
            {
                res[0][1]='.';
                res[1][1]='.';
                res[1][0]='.';
                for(int i=0;i<m;i++)
                    res[i][2]='.';
                for(int i=2;i<n;i++)
                    res[m-1][i]='.';
            }
        }
        if(k==4)
        {
            res[1][0]='.';
            res[0][1]='.';
            res[1][1]='.';
            if(m>3)
            {
                res[2][0]='.';
                res[3][0]='.';
                for(int i=0;i<m;i++)
                    res[i][1]='.';
                for(int i=1;i<n;i++)
                    res[m-1][i]='.';
            }
            else if(n>3)
            {
                res[0][2]='.';
                res[1][2]='.';
                for(int i=0;i<m;i++)
                    res[i][3]='.';
                for(int i=3;i<n;i++)
                    res[m-1][i]='.';
            }
            else
            {
                res[2][0]='.';
                res[2][1]='.';
                res[0][2]='.';
                res[1][2]='.';
                res[2][2]='.';
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    res[i][j]='.';
                }
                res[2][0]='#';
                res[0][2]='#';
                for(int i=3;i<m;i++)
                res[i][2]='.';
                for(int i=2;i<n;i++)
                res[m-1][i]='.';
            }
        }
        return res;
    }
};