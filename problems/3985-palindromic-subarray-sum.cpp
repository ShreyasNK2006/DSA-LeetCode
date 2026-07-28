/*
 * Problem 3985: Palindromic Subarray Sum
 * URL     : https://leetcode.com/problems/palindromic-subarray-sum/
 * Solved  : 2026-07-08
 * Runtime : 79 ms
 * Memory  : 226.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> build_manacher(vector<int> &nums)
    {
        vector<int> t;
        for(int x:nums)
        {
            t.push_back(0);
            t.push_back(x);
        }
        t.push_back(0);
        return t;
    }

    long long getSum(vector<int>& nums) {
        vector<int> t= build_manacher(nums);
        int s =t.size();
        vector<int> p(s,0);
        int l=0,r=0;
        for(int i=1;i<s-1;i++)
        {
            if(i<r)
            p[i]=max(0,min(r-i,p[l+r-i]));
            while(i-p[i]>0 && i+p[i]<s-1 && t[i-p[i]-1]==t[i+p[i]+1])
            {
                p[i]++;
            }
            if(i+p[i]>r)
            {
                l=i-p[i];
                r=i+p[i];
            }
        }
        vector<long long> sum(s,0);
        for(int i=0;i<s;i++)
        {
            if(i>0)
            sum[i]+=1LL*sum[i-1];
            sum[i]+=1LL*t[i];
        }
        long long maxsum=0;
        for(int i=0;i<s-1;i++)
        {
            int n=p[i];
            int l=i-n;
            int r=i+n;
            long long ls=0,rs=0;
            if(l<=0)
            ls=0;
            else
            ls=sum[l-1];
            rs=sum[r];
            maxsum=max(maxsum,rs-ls);
        }
        return maxsum;
    }
};