/*
 * Problem 3969: Valid Subarrays With Matching Sum Digits I
 * URL     : https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/
 * Solved  : 2026-06-21
 * Runtime : 355 ms
 * Memory  : 32.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        long long s=0;
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            s=0;
            for(int j=i;j<n;j++)
            {
                s=s+nums[j];
                long long d= 0;
                long long b=10;
                while(s>b)
                {
                    b*=10;
                    d++;
                }
                if(s%10==x && s/(long long)pow(10,d)==x)
                    c++;
            }
        }
        return c;
    }
};