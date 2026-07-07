/*
 * Problem 3956: Maximum Sum of M Non-Overlapping Subarrays I
 * URL     : https://leetcode.com/problems/maximum-sum-of-m-non-overlapping-subarrays-i/
 * Solved  : 2026-06-07
 * Runtime : 493 ms
 * Memory  : 230.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();
        vector<long long> prefix(n+1,0);
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,LLONG_MIN));
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        long long ans=LLONG_MIN;
        for(int k=1;k<=m;k++)
        {
            deque<int> dq;
            dp[k][n]=0;
            for(int i=n-1;i>=0;i--)
            {
                if(i+l<=n)
                {
                    long long curr= prefix[i+l]+dp[k-1][i+l];
                    while(!dq.empty())
                    {
                        int d=dq.back();
                        long long val= prefix[d]+dp[k-1][d];
                        if(curr>val)
                        dq.pop_back();
                        else
                        break;
                    }
                    dq.push_back(i+l);
                }
                while(!dq.empty() && dq.front()>i+r)
                dq.pop_front();
                dp[k][i]=dp[k][i+1];
                if(!dq.empty())
                {
                    int j=dq.front();
                    dp[k][i]=max(dp[k][i],-prefix[i]+prefix[j]+dp[k-1][j]);
                }
            }
            ans=max(ans,dp[k][0]);
        }
        long long b=LLONG_MIN;
        if(ans==0)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=l;i+j<=n && j<=r;j++)
                {
                    b=max(b,prefix[j+i]-prefix[i]);
                }
            }
            return b;
        }
        return ans;
    }
};