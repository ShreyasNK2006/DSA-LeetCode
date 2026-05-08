/*
 * Problem 1590: Make Sum Divisible by P
 * URL     : https://leetcode.com/problems/make-sum-divisible-by-p/
 * Solved  : 2026-05-02
 * Runtime : 76 ms
 * Memory  : 87.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp;
        long long prefix=0;
        int r=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
        }
        r=prefix%p;
        if(r==0)
        return 0;
        mp[0]=-1;
        int s=INT_MAX;
        prefix=0;
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            int prev=(prefix-r+p)%p;
            if(mp.find(prev)!=mp.end())
            s=min(s,i-mp[prev]);
            mp[prefix%p]=i;
        }
        if(s==INT_MAX || s==n)
        return -1;
        return s;
    }
};