/*
 * Problem 4035: Maximum Valid Split Positions I
 * URL     : https://leetcode.com/problems/maximum-valid-split-positions-i/
 * Solved  : 2026-08-29
 * Runtime : 321 ms
 * Memory  : 179.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int maxValidSplits(vector<int>& nums) {
        int maxs=0;
        int n=nums.size();
        for(int i=-1;i<n;i++)
            {
                int c=0;
                int curr=-1;
                vector<int> dp(n,-1);
                if(n-1==i)
                    dp[n-1]=-1;
                else
                dp[n-1]=nums[n-1];
                //cout<<"St\n"<<dp[n-1]<<endl;
                for(int k=n-2;k>=1;k--)
                    {
                        if(k==i)
                        {
                            if(k+1<n)
                            {
                                dp[k]=dp[k+1];
                            }
                            else
                            {
                                dp[k]=nums[k-1];
                            }
                            continue;
                        }
                        if(dp[k+1]!=-1)
                        dp[k]=gcd(dp[k+1],nums[k]);
                        else
                            dp[k]=nums[k];
                        //cout<<dp[k]<<endl;
                    }
                if(i==0)
                    curr=nums[1];
                else
                    curr=nums[0];
                for(int j=0;j<n-1;j++)
                    {
                        if(j==i)
                            continue;
                        curr=gcd(curr,nums[j]);
                        //cout<<curr<<" "<<dp[j+1]<<endl;
                        if(curr==dp[j+1])
                            c++;
                    }
                maxs=max(maxs,c);
            }
        return maxs;
    }
};