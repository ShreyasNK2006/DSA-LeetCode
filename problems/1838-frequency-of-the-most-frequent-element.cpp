/*
 * Problem 1838: Frequency of the Most Frequent Element
 * URL     : https://leetcode.com/problems/frequency-of-the-most-frequent-element/
 * Solved  : 2026-04-30
 * Runtime : 24 ms
 * Memory  : 106 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxf=1;
        int n=nums.size();
        long long sum=0;
        int l=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(1LL*(i-l+1)*nums[i]-sum>k)
            {
                sum-=nums[l];
                l++;
            }
            maxf=max(maxf,i-l+1);
        }
        return maxf;
    }
};