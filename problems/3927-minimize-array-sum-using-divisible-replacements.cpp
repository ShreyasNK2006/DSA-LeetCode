/*
 * Problem 3927: Minimize Array Sum Using Divisible Replacements
 * URL     : https://leetcode.com/problems/minimize-array-sum-using-divisible-replacements/
 * Solved  : 2026-05-14
 * Runtime : 221 ms
 * Memory  : 240.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int M=nums[n-1];
        vector<int> f(M+1,-1);
        for(int i=0;i<=M;i++)
        f[i]=i;
        set<int> st(nums.begin(),nums.end());
        for(int num:st)
        {
            if(f[num]==num)
            {
                int a=num;
                for(int k=2*a;k<=M;k+=a)
                {
                    if(f[k]==k)
                    f[k]=a;
                }
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(f[nums[i]]!=-1)
            sum+=f[nums[i]];
        }
        return sum;
    }
};