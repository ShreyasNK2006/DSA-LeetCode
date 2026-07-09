/*
 * Problem 3923: Minimum Generations to Target Point
 * URL     : https://leetcode.com/problems/minimum-generations-to-target-point/
 * Solved  : 2026-05-16
 * Runtime : 1030 ms
 * Memory  : 232.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> st;
        for(auto it: points)
        st.insert(it);
        if(st.count(target))
        return 0;
        if(points.size()==1)
        return -1;
        int gen=0;
        while(!st.count(target))
        {
            int n=points.size();
            int og=st.size();
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int x= (points[i][0]+points[j][0])/2,y=(points[i][1]+points[j][1])/2,z=(points[i][2]+points[j][2])/2;
                    if(!st.count({x,y,z}))
                    {
                        points.push_back({x,y,z});
                        st.insert({x,y,z});
                    }
                }
            }
            gen++;
                if(points.size()==n)
                return -1;
        }
        return gen;
    }
};