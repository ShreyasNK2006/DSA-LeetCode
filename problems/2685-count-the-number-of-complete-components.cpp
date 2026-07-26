/*
 * Problem 2685: Count the Number of Complete Components
 * URL     : https://leetcode.com/problems/count-the-number-of-complete-components/
 * Solved  : 2026-07-11
 * Runtime : 212 ms
 * Memory  : 137.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            continue;
            bool cond=true;
            //cout<<"level "<<i<<endl;
            unordered_set<int> st;
            st.insert(i);
            for(int e:adj[i])
            st.insert(e);
            visited[i]=1;
            int t=adj[i].size();
            int c=0;
            for(int e:adj[i])
            {
                c=0;
                visited[e]=1;
                for(int x:adj[e])
                {
                    if(st.find(x)!=st.end())
                    c++;
                    else
                    cond=false;
                }
                if(c!=t)
                cond=false;
            }
            cout<<t<<endl;
            cout<<cond<<endl;
            cout<<c<<endl;
           if(cond)
           count++;
        }
        return count;
    }
};