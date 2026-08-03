/*
 * Problem 3984: Divisible Game
 * URL     : https://leetcode.com/problems/divisible-game/
 * Solved  : 2026-07-07
 * Runtime : 366 ms
 * Memory  : 36.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define mod 1000000007
class Solution {
public:
    /*void solve(int &n,int k,int &mink,int &maxdiff,vector<int>&nums)
    {
                vector<int> dp(n);
                for(int j=0;j<n;j++)
                    {
                        int s=0;
                        if(nums[j]%k==0)
                            s=nums[j];
                        else
                            s=-nums[j];
                        //cout<<s<<endl;
                        if(j==0)
                        {    
                            dp[j]=s;
                        }
                        else
                        {
                            dp[j]=max(dp[j-1]+s,s);
                        }
                        //cout<<dp[j][i]<<endl;
                        if(maxdiff<dp[j])
                        {
                            maxdiff=dp[j];
                            mink=k;
                        }
                    }
    }*/
    void sieve(unordered_set<int> &st,vector<int> &nums)
    {
        st.insert(2);
        for(auto x:nums)
        {
            for(long long i=1;i*i<=x;i++)
            {
                if(x%i==0)
                {
                    if(i>1)
                    st.insert(i);
                    if(x/i>1)
                    st.insert(x/i);
                }
            }
        }
    }
    int divisibleGame(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        sieve(st,nums);
        int mink=2;
        long long maxdiff=-1;
        vector<int> dp(n);
        for(auto i: st)
            {
                for(int j=0;j<n;j++)
                    {
                        int s=0;
                        if(nums[j]%i==0)
                            s=nums[j];
                        else
                            s=-nums[j];
                        //cout<<s<<endl;
                        if(j==0)
                        {    
                            dp[j]=s;
                        }
                        else
                        {
                            dp[j]=max(dp[j-1]+s,s);
                        }
                        //cout<<dp[j][i]<<endl;
                        if(maxdiff<dp[j])
                        {
                            maxdiff=dp[j];
                            mink=i;
                        }
                        else if(maxdiff==dp[j])
                        {
                            mink=min(mink,i);
                        }
                    }
            }
            //cout<<maxdiff;
        return (int)((maxdiff*mink+mod)%mod);
    }
};