/*
 * Problem 0532: K-diff Pairs in an Array
 * URL     : https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * Solved  : 2026-07-10
 * Runtime : 174 ms
 * Memory  : 15.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int c=0;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        int f=0;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]  && f==0)
            {
                if(k==0)
                c++;
                f=1;
            }
            if(nums[i]==nums[i-1] && f==1)
            continue;
            else
            f=0;
            temp.push_back(nums[i]);
        }
        for(int i=0;i<temp.size();i++)
        {
            for(int j=i+1;j<temp.size();j++)
            {
                if(abs(temp[i]-temp[j])==k)
                c++;
            }
        }
        return c;
    }
};