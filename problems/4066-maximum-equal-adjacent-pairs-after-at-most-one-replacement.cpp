/*
 * Problem 4066: Maximum Equal Adjacent Pairs After at Most One Replacement
 * URL     : https://leetcode.com/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/
 * Solved  : 2026-09-27
 * Runtime : 537 ms
 * Memory  : 327.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int> mp;
        //unordered_map<int,vector<pair<int,int>>> mp2;
        int n= nums.size();
        int c=0;
        for(int i=0;i<n-1;i++)
        {
            int x = nums[i], y= nums[i+1];
            mp[{min(x,y),max(x,y)}]++;
            
        }
        int b=0;
            for(auto it:mp)
                {
                    int x =it.first.first, y = it.first.second;
                if(x==y)
                {
                    b+=it.second;
                }
                }
            c=b;
        for(auto it:mp)
            {
                int x =it.first.first, y = it.first.second;
                if(x==y)
                {
                    continue;
                }
                c = max(c,b+it.second);
            }
        return c;
    }
};