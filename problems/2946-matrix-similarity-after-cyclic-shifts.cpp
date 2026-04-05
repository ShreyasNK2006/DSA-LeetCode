/*
 * Problem 2946: Matrix Similarity After Cyclic Shifts
 * URL     : https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
 * Solved  : 2026-03-28
 * Runtime : 0 ms
 * Memory  : 31.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i%2==0)
                {
                    if(mat[i][j]==mat[i][(j+k)%n])
                    continue;
                    else
                    return false;
                }
                else
                {
                    if(mat[i][n-1-j]==mat[i][(n-1-(j+k)%n)])
                    continue;
                    else
                    return false;
                }
            }
        }
        return true;
    }
};