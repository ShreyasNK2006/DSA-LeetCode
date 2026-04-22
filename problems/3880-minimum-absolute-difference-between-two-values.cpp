/*
 * Problem 3880: Minimum Absolute Difference Between Two Values
 * URL     : https://leetcode.com/problems/minimum-absolute-difference-between-two-values/
 * Solved  : 2026-03-28
 * Runtime : 0 ms
 * Memory  : 26 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int minn=INT_MAX;
        vector<int> one,two;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==1)
                    one.push_back(i);
                else if(nums[i]==2)
                    two.push_back(i);
            }
        int i=0,j=0;
        while(i<one.size())
            {
                while(j<two.size())
                    {
                        minn=min(minn,abs(two[j]-one[i]));
                        j++;
                    }
                j=0;
                i++;
            }
        return minn!=INT_MAX?minn:-1;
    }
};