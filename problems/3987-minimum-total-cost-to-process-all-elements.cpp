/*
 * Problem 3987: Minimum Total Cost to Process All Elements
 * URL     : https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/
 * Solved  : 2026-07-12
 * Runtime : 13 ms
 * Memory  : 169.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define mod 1000000007
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        unsigned long long cost=0;
        unsigned long long c=0;
        unsigned long long b=k;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<=b)
                {
                    b-=nums[i];
                }
                else
                {
                    unsigned long long x= (nums[i]-b)/k;
                    if((nums[i]-b)%k!=0)
                        x++;
                    b+=x*k;
                    cost=(cost%mod+(((x)*(x+1))/2)%mod+(c%mod)*(x%mod)%mod);
                    c=c+x;
                    b=b-nums[i];
                }
            }
        int res =(int)(cost%mod);
        return res;
    }
};