/*
 * Problem 1345: Jump Game IV
 * URL     : https://leetcode.com/problems/jump-game-iv/
 * Solved  : 2026-05-18
 * Runtime : 106 ms
 * Memory  : 80 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<bool> visited(n,false);
        unordered_set<int> st;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        mp[arr[i]].push_back(i);
        queue<int> q;//dist,ind
        q.push({0});
        int l=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int ind=q.front();
                if(ind==n-1)
                return l;
                q.pop();
                if(visited[ind]==false)
                {
                    visited[ind]=true;
                    int lft=ind-1;
                    int rt=ind+1;
                    if(lft>=0)
                    {
                        if(st.find(arr[lft])==st.end())
                        q.push(lft);
                    }
                    if(rt<n)
                    {
                        if(st.find(arr[rt])==st.end())
                        q.push(rt);
                    }
                    if(st.find(arr[ind])==st.end())
                    for(auto it:mp[arr[ind]])
                    {
                        if(it!=ind)
                        q.push(it);
                    }
                    st.insert(arr[ind]);
                }
            }
            l++;
        }
        return l;
    }
};