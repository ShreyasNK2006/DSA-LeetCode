/*
 * Problem 3116: Kth Smallest Amount With Single Denomination Combination
 * URL     : https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/
 * Solved  : 2026-08-24
 * Runtime : 11 ms
 * Memory  : 21.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<long long> lcm;
    vector<int> bitcount;
    long long m;
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        m= 1<<n;
        lcm.resize(m);
        bitcount.resize(m,0);
        long long l =k,r=25;
        for(auto it:coins)
        r=min(r,1LL*it);
        r*=k;
        r++;
        //sort(coins.begin(),coins.end());
        for(int i=1;i<m;i++)
        {
            long long curlcm =1;
            for(int j=0;j<n;j++)
            {
                if(i>>j & 1)
                {
                    long long temp = curlcm/gcd(curlcm,coins[j]);
                    if(temp<=r/coins[j])
                    {
                        curlcm = temp*coins[j];
                    }
                    else
                    {
                        curlcm = r+1;
                        break;
                    }
                    bitcount[i]++;
                }
            }
            lcm[i]=curlcm;
        }
        while(l<r)
        {
            long long x =(l+r)/2;
            if(get(x)>=k)
            {
                r=x;
            }
            else
            {
                l=x+1;
            }
        }
        return l;
    }
    long long get(long long x)
    {
        long long count=0;
        for(int i=1;i<m;i++)
        {
            if(lcm[i]>x)
            continue;
            if(bitcount[i]&1)
            count+=x/lcm[i];
            else
            count-=x/lcm[i];
        }
        return count;
    }
};