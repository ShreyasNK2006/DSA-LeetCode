/*
 * Problem 0053: Maximum Subarray
 * URL     : https://leetcode.com/problems/maximum-subarray/
 * Solved  : 2026-09-27
 * Runtime : 12 ms
 * Memory  : 87.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long maxsum=-10000;
        vector<long long> suffix(n,0),prefix(n,0);
        for(int i=n-1;i>=0;i--)
        {
            suffix[i]=nums[i];
            if(i<n-1)
            suffix[i]+=suffix[i+1];
            maxsum = max(maxsum,1LL*nums[i]);
        }
        vector<long long> ts(n,suffix[0]);
        for(int i=0;i<n;i++)
        {
            prefix[i]=nums[i];
            if(i>0)
            prefix[i]+=prefix[i-1];
        }
        long long rm =0;
        for(int i=n-1;i>=0;i--)
        {
            suffix[i]-=rm;
            ts[i]-=rm;
            if(suffix[i]<0)
            {
                rm+=suffix[i];
            }
        }
        rm=0;
        for(int i=0;i<n;i++)
        {
            maxsum=max(maxsum,ts[i]-rm);
            prefix[i]-=rm;
            if(prefix[i]<0)
            {
                rm+=prefix[i];
            }
            
        }
        return maxsum;
    }
};