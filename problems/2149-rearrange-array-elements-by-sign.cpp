/*
 * Problem 2149: Rearrange Array Elements by Sign
 * URL     : https://leetcode.com/problems/rearrange-array-elements-by-sign/
 * Solved  : 2026-05-01
 * Runtime : 11 ms
 * Memory  : 128.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int f=0,s=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                while(nums[f]<0)
                f++;
                res[i]=nums[f];
                f++;
            }
            else
            {
                while(nums[s]>0)
                s++;
                res[i]=nums[s];
                s++;
            }
        }
        return res;
    }
};