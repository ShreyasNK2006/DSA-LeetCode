/*
 * Problem 1878: Get Biggest Three Rhombus Sums in a Grid
 * URL     : https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
 * Solved  : 2026-03-16
 * Runtime : 263 ms
 * Memory  : 68.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        set<int> st;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                st.insert(grid[i][j]); 

                for(int k=1;;k++)
                {
                    if(i-k<0 || i+k>=m || j-k<0 || j+k>=n)
                        break;

                    int sum=0;

                    for(int d=0;d<k;d++)
                    {
                        sum+=grid[i-k+d][j+d];
                        sum+=grid[i+d][j+k-d];
                        sum+=grid[i+k-d][j-d];
                        sum+=grid[i-d][j-k+d];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> res(st.begin(),st.end());
        sort(res.rbegin(),res.rend());

        if(res.size()>3) res.resize(3);
        return res;
    }
};