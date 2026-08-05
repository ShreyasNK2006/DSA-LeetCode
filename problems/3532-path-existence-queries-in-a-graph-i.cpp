/*
 * Problem 3532: Path Existence Queries in a Graph I
 * URL     : https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
 * Solved  : 2026-07-09
 * Runtime : 0 ms
 * Memory  : 224 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]-nums[i]<=maxDiff)
            parent[i]=parent[i+1];
        }
        int q=queries.size();
        vector<bool> ans(q);
        for(int i=0;i<q;i++)
        {
            if(parent[queries[i][0]]==parent[queries[i][1]])
            ans[i]=true;
            else
            ans[i]=false;
        }
        return ans;
    }
};