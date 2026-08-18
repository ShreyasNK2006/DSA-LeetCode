/*
 * Problem 1979: Find Greatest Common Divisor of Array
 * URL     : https://leetcode.com/problems/find-greatest-common-divisor-of-array/
 * Solved  : 2026-07-18
 * Runtime : 0 ms
 * Memory  : 16.2 MB
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
    int findGCD(vector<int>& nums) {
        int minn=INT_MAX,maxn= INT_MIN;
        for(auto x:nums)
        {
            minn=min(minn,x);
            maxn=max(maxn,x);
        }
        int res = gcd(maxn,minn);
        return res;
    }
};