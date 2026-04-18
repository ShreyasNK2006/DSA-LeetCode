/*
 * Problem 0740: Delete and Earn
 * URL     : https://leetcode.com/problems/delete-and-earn/
 * Solved  : 2026-04-03
 * Runtime : 7 ms
 * Memory  : 17.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int> dp(mp.size(),0);
        int pos=0,prev=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(pos==0)
            dp[0]=(it->first)*(it->second);
            else if(pos==1)
            {
                if(it->first-prev>1)
                dp[1]=dp[0]+(it->first)*(it->second);
                else
                dp[1]=max(dp[0],(it->first)*(it->second));
            }
            else
            {
                if(it->first-prev==1)
                dp[pos]=max(dp[pos-2]+((it->first)*(it->second)),dp[pos-1]);
                else
                dp[pos]=dp[pos-1]+((it->first)*(it->second));
            }
            pos++;
            prev=it->first;
        }
        return dp[pos-1];
    }
};