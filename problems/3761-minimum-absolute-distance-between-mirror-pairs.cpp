/*
 * Problem 3761: Minimum Absolute Distance Between Mirror Pairs
 * URL     : https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
 * Solved  : 2026-04-17
 * Runtime : 325 ms
 * Memory  : 204.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int reverse(int n)
    {
        int newnum=0;
        while(n)
        {
            newnum*=10;
            newnum+=(n%10);
            n/=10;
        }
        return newnum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        int mindiff=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int rev = reverse(nums[i]);
            auto it= lower_bound(mp[rev].begin(),mp[rev].end(),i);
            if(it!=mp[rev].end())
            {
                if(*it!=i)
                mindiff=min(mindiff,abs(i-*it));
                else if(it+1!=mp[rev].end())
                mindiff=min(mindiff,abs(i-*(it+1)));
            }
        }
        return mindiff!=INT_MAX?mindiff:-1;
    }
};