/*
 * Problem 3312: Sorted GCD Pair Queries
 * URL     : https://leetcode.com/problems/sorted-gcd-pair-queries/
 * Solved  : 2026-07-17
 * Runtime : 45 ms
 * Memory  : 123.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<int> res;
        int maxe=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        maxe=max(maxe,nums[i]);
        vector<long long> cnt(maxe+1,0);
        for(int i=0;i<n;i++)
        {
            cnt[nums[i]]++;
        }
        for(int i=1;i<=maxe;i++)
        {
            for(int j=i*2;j<=maxe;j+=i)
            {
                cnt[i]+=cnt[j];
            }
        }
        for(int i=1;i<=maxe;i++)
        {
            cnt[i]=cnt[i]*(cnt[i]-1)/2;
        }
        for(int i=maxe;i>=1;i--)
        {
            for(int j=i*2;j<=maxe;j+=i)
            cnt[i]-=cnt[j];
        }
        for(int i=1;i<=maxe;i++)
        cnt[i]+=cnt[i-1];
        for(auto q:queries)
        {
            q++;
            long long l=1,r=maxe;
            int ans=maxe;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                if(1LL*cnt[mid]<q)
                {
                    l=mid+1;
                }
                else if(1LL*cnt[mid]>=q)
                {
                    r=mid-1;
                    ans=mid;
                }
            }
            res.push_back(ans); 
        }
        return res;
    }
};