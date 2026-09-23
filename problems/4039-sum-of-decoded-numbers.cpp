/*
 * Problem 4039: Sum of Decoded Numbers
 * URL     : https://leetcode.com/problems/sum-of-decoded-numbers/
 * Solved  : 2026-08-30
 * Runtime : 419 ms
 * Memory  : 262.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define mod 1000000007
class Solution {
public:
    long long power(long long x,long long y)
    {
        long long ans=1;
        while(y)
            {
                if(y & 1)
                {
                    ans=(ans*x)%mod;
                }
                x=(x*x)%mod;
                y=y>>1;
            }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long sum =0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            {
                long long w = nums[i]%10;
                long long d = nums[i]/10;
                long long x =0;
                long long y=0;
                vector<long long> temp;
                while(d)
                    {
                        long long m = d%10;
                        d/=10;
                        temp.push_back(m);
                    }
                int k = temp.size();
                for(int j=0;j<w;j++)
                    {
                        x*=10;
                        x+=temp[k-1-j];
                    }
                y=0;
                for(int j=w;j<k;j++)
                    {
                        y*=10;
                        y+=temp[k-1-j];
                    }
                long long prod=1;
                prod =power(x,y);
                sum=(sum+prod)%mod;
            }
        return sum;
    }
};