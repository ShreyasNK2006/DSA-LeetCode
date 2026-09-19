/*
 * Problem 4032: Longest Subarray With at Most K Distinct Prime Factors
 * URL     : https://leetcode.com/problems/longest-subarray-with-at-most-k-distinct-prime-factors/
 * Solved  : 2026-08-23
 * Runtime : 1276 ms
 * Memory  : 385.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> prime;
    void sieve(int n)
    {
        prime.resize(n+1,1);
        prime[0]=-1;
        prime[1]=-1;
        for(int i=2;i*i<=n;i++)
            {
                if(prime[i]==1)
                {
                    for(int j=i*i;j<=n;j+=i)
                        prime[j]=-1;
                }
            }
    }

    int longestSubarray(vector<int>& nums, int k) {
        int maxl=0;
        int n=nums.size();
        sieve(1e5);
        int c=0;
        vector<vector<int>> fact(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    if(prime[j]==1)
                    {
                        fact[i].push_back(j);
                    }
                    if(j!=nums[i]/j)
                    {
                        if(prime[nums[i]/j]==1)
                        fact[i].push_back(nums[i]/j);
                    }
                }
            }
        }
        int l=0,r=0;
        unordered_map<int,int>mp;
        while(r<n)
        {
            //cout<<l<<endl;
            for(auto it:fact[r])
            {
                mp[it]++;
                //cout<<it<<endl;
            }
            if(mp.size()<=k)
            maxl=max(maxl,r-l+1);
            else 
            {
                while(mp.size()>k)
                {
                    for(auto it:fact[l])
                    {
                        mp[it]--;
                        if(mp[it]==0)
                        mp.erase(it);
                    }
                    l++;
                }
            }
            r++;
        }
        return maxl;
    }
};