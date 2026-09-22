/*
 * Problem 2091: Removing Minimum and Maximum From Array
 * URL     : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
 * Solved  : 2026-08-30
 * Runtime : 3 ms
 * Memory  : 92.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mine =INT_MAX,maxe=INT_MIN;
        int in1=-1,in2=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mine>nums[i])
            {
                mine=nums[i];
                in1=i;
            }
            if(maxe<nums[i])
            {
                maxe=nums[i];
                in2=i;
            }
        }
        int ans=INT_MAX;
        ans =min(max(in1,in2)+1,n-(min(in1,in2)));
        ans=min(ans,min(in1,in2)+n-max(in1,in2)+1);
        return ans;
    }
};