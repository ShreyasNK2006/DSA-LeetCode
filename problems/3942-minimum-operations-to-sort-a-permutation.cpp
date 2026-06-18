/*
 * Problem 3942: Minimum Operations to Sort a Permutation
 * URL     : https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/
 * Solved  : 2026-05-30
 * Runtime : 0 ms
 * Memory  : 141.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minn=INT_MAX;
        int n=nums.size();
        // checking if sorted in ascending order 2 split
        {
            int split=n;
            for(int i=1;i<n;i++)
                {
                    if(nums[i-1]<nums[i])
                    {
                        continue;
                    }
                    else
                    {
                        split=i;
                        break;
                    }
                }
            bool pass=true;
            for(int i=split+1;i<n;i++)
                {
                    if(nums[i-1]<nums[i])
                    {
                        continue;
                    }
                    else
                    {
                        pass=false;
                        break;
                    }
                }
            if(nums[0]>nums[n-1] && pass)
                minn=min(minn,min(split,2+n-split));
            if(split==n)
                minn=0;
        }
        //checking for reverse
        {
            int split=0;
            for(int i=n-1;i>0;i--)
                {
                    if(nums[i-1]>nums[i])
                    {
                        continue;
                    }
                    else
                    {
                        split=i;
                        break;
                    }
                }
            bool pass=true;
            for(int i=split-1;i>0;i--)
                {
                    if(nums[i-1]>nums[i])
                    {
                        continue;
                    }
                    else
                    {
                        pass=false;
                        break;
                    }
                }
            if(nums[0]<nums[n-1] && pass)
                minn=min(minn,1+min(split,n-split));
            cout<<split;
            if(split==0)
                minn=min(minn,1);
        }
        if(minn!=INT_MAX)
            return minn;
        else return -1;
    }
};