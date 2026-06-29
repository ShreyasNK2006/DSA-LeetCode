/*
 * Problem 0018: 4Sum
 * URL     : https://leetcode.com/problems/4sum/
 * Solved  : 2026-06-09
 * Runtime : 31 ms
 * Memory  : 17.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(i>0 && i<n && nums[i]==nums[i-1])
            {
                i++;
                continue;
            }
            for(int j=i+1;j<n;j++)
            {
                while(j>i+1 && j<n && nums[j]==nums[j-1])
                j++;
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long sum=1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target)
                    {
                        vector<int> temp ={nums[i],nums[j],nums[k],nums[l]};
                        res.push_back(temp);
                        k++;
                        l--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    l--;
                    while(k<l && k>j+1 && nums[k]==nums[k-1])
                    k++;
                    while(k<l && l<n-1 && nums[l]==nums[l+1])
                    l--;
                }
            }
        }
        return res;
    }
};