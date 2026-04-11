/*
 * Problem 1886: Determine Whether Matrix Can Be Obtained By Rotation
 * URL     : https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
 * Solved  : 2026-03-22
 * Runtime : 0 ms
 * Memory  : 14.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool find=true;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=target[i][j])
                {
                    find=false;
                    break;
                }
            }
            if(find==false)
            break;
        }
        if(find==true)
        return true;
        find=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=target[n-1-i][n-1-j])
                {
                    find=false;
                    break;
                }
            }
            if(find==false)
            break;
        }
        if(find==true)
        return true;
        find=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=target[j][n-1-i])
                {
                    find=false;
                    break;
                }
            }
            if(find==false)
            break;
        }
        if(find==true)
        return true;
        find=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=target[n-1-j][i])
                {
                    find=false;
                    break;
                }
            }
            if(find==false)
            break;
        }
        return find;
    }
};