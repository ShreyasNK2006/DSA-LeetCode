/*
 * Problem 3912: Valid Elements in an Array
 * URL     : https://leetcode.com/problems/valid-elements-in-an-array/
 * Solved  : 2026-05-06
 * Runtime : 0 ms
 * Memory  : 32.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution{
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> gr(n,1);
        int m=nums[n-1];
        for(int i=n-2;i>=0;i--)
            {
                if(nums[i]>m)
                {
                    gr[i]=1;
                }
                else
                {
                    gr[i]=-1;
                }
                m=max(m,nums[i]);
            }
        gr[0]=1;
        int m2=nums[0];
        vector<int> res;
        for(int i=0;i<n;i++)
            {
                if(nums[i]>m2 || gr[i]==1)
                {
                    res.push_back(nums[i]);
                }
                m2=max(m2,nums[i]);
            }
        return res;
    }
};