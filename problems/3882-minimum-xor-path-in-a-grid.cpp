/*
 * Problem 3882: Minimum XOR Path in a Grid
 * URL     : https://leetcode.com/problems/minimum-xor-path-in-a-grid/
 * Solved  : 2026-03-28
 * Runtime : 2682 ms
 * Memory  : 520.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public: 

    int minCost(vector<vector<int>>& grid) {
        int minn=INT_MAX;
        int m=grid.size(),n=grid[0].size();
        vector<vector<unordered_set<int>>> mp(m,vector<unordered_set<int>>(n));
        mp[0][0].insert(grid[0][0]);
        for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if(i==0 && j==0)
                            continue;
                        if(i>0)
                        for(auto it:mp[i-1][j])
                            mp[i][j].insert(grid[i][j]^it);
                        if(j>0)
                        for(auto it:mp[i][j-1])
                            mp[i][j].insert(grid[i][j]^it);
                    }
            }
        for(auto it:mp[m-1][n-1])
            minn=min(minn,it);
        return minn;
    }
};