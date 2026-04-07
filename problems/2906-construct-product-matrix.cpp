/*
 * Problem 2906: Construct Product Matrix
 * URL     : https://leetcode.com/problems/construct-product-matrix/
 * Solved  : 2026-03-24
 * Runtime : 49 ms
 * Memory  : 140.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define MOD 12345
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<long long> prefix(m*n+1,1),suffix(m*n+1,1);
        int x=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                prefix[x+1]=prefix[x];
                suffix[m*n-x-1]=suffix[m*n-x];
                x++;
                prefix[x]=(prefix[x]*grid[i][j])%MOD;
                suffix[m*n-x]=(suffix[m*n-x]*grid[m-i-1][n-1-j])%MOD;
            }
        }
        x=0;
        vector<vector<int>> p(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                p[i][j]=(prefix[x]*suffix[x+1])%MOD;
                x++;
            }
        }
        return p;
    }
};