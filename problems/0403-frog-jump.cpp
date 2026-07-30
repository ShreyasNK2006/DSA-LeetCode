/*
 * Problem 0403: Frog Jump
 * URL     : https://leetcode.com/problems/frog-jump/
 * Solved  : 2026-05-19
 * Runtime : 218 ms
 * Memory  : 52.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_set<long long> st;
        set<pair<int,int>> visited;
        for(int i=0;i<n;i++)
        st.insert(stones[i]);
        if(st.find(1)==st.end())
        return false;
        long long dsnt=stones[n-1];
        queue<pair<long long,long long>> q;
        q.push({1,1});
        visited.insert({0,0});
        visited.insert({1,1});
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                long long k=q.front().second;
                long long step=q.front().first;
                q.pop();
                if(step==dsnt)
                return true;
                if(st.find(step+k)!=st.end() && visited.find({step+k,k})==visited.end())
                {
                    visited.insert({step+k,k});
                    q.push({step+k,k});
                }
                if(st.find(step+k-1)!=st.end() && visited.find({step+k-1,k-1})==visited.end())
                {
                    visited.insert({step+k-1,k-1});
                    q.push({step+k-1,k-1});
                }
                if(st.find(step+k+1)!=st.end() && visited.find({step+k+1,k+1})==visited.end())
                {
                    visited.insert({step+k+1,k+1});
                    q.push({step+k+1,k+1});
                }
            }
        }
        return false;
    }
};