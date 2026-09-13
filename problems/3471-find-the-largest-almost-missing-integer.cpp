/*
 * Problem 3471: Find the Largest Almost Missing Integer
 * URL     : https://leetcode.com/problems/find-the-largest-almost-missing-integer/
 * Solved  : 2026-08-18
 * Runtime : 5 ms
 * Memory  : 29.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(auto it:nums)
        {
            mp[it]++;
        }
        if(k==n)
        {
            int res=0;
            for(auto it:mp)
            res=max(res,it.first);
            return res;
        }
        else if(k>1)
        {
            int res=-1;
            if(mp[nums[0]]==1)
            res=nums[0];
            if(mp[nums[n-1]]==1)
            res=max(res,nums[n-1]);
            return res;
        }
        else{
            int res=-1;
            for(auto it:mp)
            {
                if(it.second==1)
                res=max(res,it.first);
            }
            return res;
        }
        return -1;
    }
};