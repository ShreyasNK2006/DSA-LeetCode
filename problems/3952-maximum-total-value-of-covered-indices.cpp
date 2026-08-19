/*
 * Problem 3952: Maximum Total Value of Covered Indices
 * URL     : https://leetcode.com/problems/maximum-total-value-of-covered-indices/
 * Solved  : 2026-06-06
 * Runtime : 40 ms
 * Memory  : 219.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans=0;
        int n=nums.size();
        vector<pair<long long,long long>> presum(n);
        if(s[n-1]=='1')
        {
            presum[n-1]={nums[n-1],nums[n-1]};
            ans=nums[n-1];
        }
        else
            presum[n-1]={-1,-1};
        for(int i=n-2;i>=0;i--)
            {
                if(s[i]=='1')
                {
                    presum[i].first=nums[i];
                    presum[i].second=nums[i];
                    if(presum[i+1].second!=-1)
                    {
                        presum[i].first+=presum[i+1].first;
                        presum[i].second=min(presum[i].second,presum[i+1].second);
                    }
                    ans+=nums[i];
                }
                else
                {
                    if(s[i+1]=='1' && nums[i]>presum[i+1].second)
                    {
                        presum[i].first=presum[i+1].first+nums[i]-presum[i+1].second;
                        presum[i].second=-1;
                        ans=ans+nums[i]-presum[i+1].second;
                    }
                    else
                        presum[i]={-1,-1};
                }
            }
        return ans;
    }
};