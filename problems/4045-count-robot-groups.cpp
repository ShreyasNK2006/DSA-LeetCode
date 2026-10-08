/*
 * Problem 4045: Count Robot Groups
 * URL     : https://leetcode.com/problems/count-robot-groups/
 * Solved  : 2026-09-06
 * Runtime : 0 ms
 * Memory  : 202.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int grp =1;
        int n= position.size();
        int cs=speed[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if((position[i+1]-position[i])<=distance || cs<speed[i])
            {
                //cout<<i<<endl;
                continue;
            }
            else 
            {
                grp++;
                cs=speed[i];
            }
        }
        return grp;
    }
};