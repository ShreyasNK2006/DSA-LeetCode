/*
 * Problem 3761: Minimum Absolute Distance Between Mirror Pairs
 * URL     : https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
 * Solved  : 2026-04-17
 * Runtime : 924 ms
 * Memory  : 166.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int reverse(int x)
    {
        int res=0;
        while(x)
            {
                res*=10;
                res+=(x%10);
                x/=10;
            }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int mind=INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
            {
                mp[nums[i]].push_back(i);
            }
        for(int i=0;i<nums.size();i++)
            {
                int temp = reverse(nums[i]);
                if(mp.find(temp)!=mp.end())
                {
                    for(int j=0;j<mp[temp].size();j++)
                        {
                            if(i==mp[temp][j])
                                continue;
                            mind=min(mind,(abs(i-mp[temp][j])));
                            if(mind==1)
                                return 1;
                        }
                }
                mp[nums[i]].erase(mp[nums[i]].begin());
                if(mp[nums[i]].empty())
                    mp.erase(nums[i]);
            }
        if(mind!=INT_MAX)
        return mind;
        else
            return -1;
    }
};