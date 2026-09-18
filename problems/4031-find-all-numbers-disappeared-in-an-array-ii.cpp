/*
 * Problem 4031: Find All Numbers Disappeared in an Array II
 * URL     : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/
 * Solved  : 2026-08-23
 * Runtime : 104 ms
 * Memory  : 243.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=lower;
        vector<vector<int>> res;
        if(nums[0]>upper)
        {
            res.push_back({lower,upper});
            return res;
        }
        else if(nums[0]==upper)
        {
            if(upper-1>=lower)
            {
                res.push_back({lower,upper-1});
            }
            return res;
        }
        for(int i=0;i<n;i++)
            {
                if(nums[i]>=upper)
                {
                    if(i>0)
                    {
                        if(upper<nums[i] && l<=upper)
                        res.push_back({l,upper});
                        else if(l<upper)
                            res.push_back({l,upper-1});
                    }
                    break;
                }
                if(nums[i]>l)
                {
                    res.push_back({l,nums[i]-1});
                    l=nums[i]+1;
                }
                else if(nums[i]==l)
                    l++;
            }
        if(nums[n-1]<upper)
        {
            res.push_back({max(nums[n-1]+1,lower),upper});
        }
        return res;
    }
};