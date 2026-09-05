/*
 * Problem 4010: Maximize Pair Strength Using GCD
 * URL     : https://leetcode.com/problems/maximize-pair-strength-using-gcd/
 * Solved  : 2026-08-12
 * Runtime : 941 ms
 * Memory  : 37.4 MB
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
    long long maxPairStrength(vector<int>& nums) {
        long long res=0;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                    {
                        int g= gcd(nums[i],nums[j]);
                        res=max(res,(1LL*nums[i]*nums[j])/(1LL*g*g));
                    }
            }
        return res;
    }
};