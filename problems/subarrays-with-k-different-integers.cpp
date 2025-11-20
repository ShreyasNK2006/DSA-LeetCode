# Subarrays with K Different Integers
Solved on 2025-11-15

class Solution {
public:
    int countsub(vector<int> &nums, int k)
    {
        int count=0;
        int l=0,r=0;
        unordered_map<int,int> mp;
        while(r<nums.size())
        {
            mp[nums[r]]++;
            if(mp[nums[r]]==1)
            k--;
            while(k<0)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                k++;
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res = countsub(nums,k)-countsub(nums,k-1);
        return res;
    }
};