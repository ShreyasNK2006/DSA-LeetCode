/*
 * Problem 1331: Rank Transform of an Array
 * URL     : https://leetcode.com/problems/rank-transform-of-an-array/
 * Solved  : 2026-07-12
 * Runtime : 15 ms
 * Memory  : 37.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> st(n);
        for(int i=0;i<n;i++)
        st[i]={arr[i],i};
        sort(st.begin(),st.end());
        vector<int> rank(n);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(i>0 && st[i].first==st[i-1].first)
            rank[st[i].second]=c;
            else
            {
                rank[st[i].second]=c+1;
                c++;
            }
        }
        return rank;
    }
};