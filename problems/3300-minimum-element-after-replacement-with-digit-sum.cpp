/*
 * Problem 3300: Minimum Element After Replacement With Digit Sum
 * URL     : https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
 * Solved  : 2026-05-29
 * Runtime : 0 ms
 * Memory  : 27.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minElement(vector<int>& nums) {
        int minsum=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int dsum=0;
            while(nums[i])
            {
                dsum+=(nums[i]%10);
                nums[i]/=10;
            }
            minsum=min(minsum,dsum);
        }
        return minsum;
    }
};