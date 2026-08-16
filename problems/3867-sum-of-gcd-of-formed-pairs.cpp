/*
 * Problem 3867: Sum of GCD of Formed Pairs
 * URL     : https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
 * Solved  : 2026-07-16
 * Runtime : 60 ms
 * Memory  : 155.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int gcd(int n1,int n2)
    {
        while(n1>0 && n2>0)
            {
                if(n1>n2)
                {
                    n1%=n2;
                }
                else
                {
                    n2%=n1;
                }
            }
        if(n1==0)
            return n2;
        else
            return n1;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> pregcd(nums.size());
        int maxn=INT_MIN;
        for(int i=0;i<nums.size();i++)
            {
                maxn=max(maxn,nums[i]);
                pregcd[i]=gcd(nums[i],maxn);
            }
        sort(pregcd.begin(),pregcd.end());
        long long sum=0;
        for(int i=0;i<nums.size()/2;i++)
            {
                sum+=(gcd(pregcd[i],pregcd[nums.size()-1-i]));
            }
        return sum;
    }
};